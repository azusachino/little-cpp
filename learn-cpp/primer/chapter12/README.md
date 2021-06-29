# 动态内存

全局对象在程序启动时分配，在程序结束时销毁。对于局部自动对象，当我们进入其定义所在的程序块时被创建，在离开块时销毁。局部 static 对象在第一次使用前分配，在程序结束时销毁。

## 动态内存和智能指针

动态内存的管理是通过一对运算符来完成的：`new`，在动态内存中为对象分配空间并返回一个指向该对象的指针，我们可以选择对对象进行初始化；`delete`，接受一个动态对象的指针，销毁该对象，并释放与之关联的内存。

新的标准库提供了两种智能指针（smart
pointer）类型来管理动态对象。智能指针的行为类似常规指针，重要的区别是它负责自动释放所指向的对象。新标准库提供的这两种智能指针的区别在于管理底层指针的方式：shared_ptr 允许多个指针指向同一个对象；unique_ptr 则“独占”所指向的对象。标准库还定义了一个名为 weak_ptr 的伴随类，它是一种弱引用，指向 shared_ptr 所管理的对象。 `#include <memory>`

### shared_ptr

默认初始化的智能指针中保存着一个空指针。

最安全的分配和使用动态内存的方法是调用一个名为 make_shared 的标准库函数。此函数在动态内存中分配一个对象并初始化它，返回指向此对象的 shared_ptr。

make_shared 用其参数来构造给定类型的对象。

```c++
shared_ptr<string> sp;
if (sp && sp->empty()) {
    *sp = "HI";
}
shared_ptr<int> isp = make_shared<int>(42);
auto ap = make_shared<vector<string>>();
```

### 直接管理内存

运算符 new 分配内存，delete 释放 new 分配的内存。

```c++
int *pi = new int; // pi指向一个动态分配、未初始化的无名对象

auto p1 = new auto(obj); // p1指向一个与obj类型相同的对象
auto p2 = new auto(a,b,c); // 错误，括号中只能由单个初始化器

const int *pc1 = new const int(1024);
const int *pc2 = new const string; // 分配并默认初始化一个const的空string

// 如果内存耗尽，分配失败，new抛出std::bad_alloc
int *p3 = new int;
int *p4 = new (nothrow) int; // 如果分配失败，new返回一个空指针

delete pi; // 释放动态内存


int *p(new int(42)); // p指向动态内存
auto q = p; // p和q指向相同的内存
delete p; // p和q均变为无效
p = nullptr; // 指出p不再绑定到任何对象
```

### shared_ptr 和 new 结合使用

接受指针参数的智能指针构造函数是 explicit 的。因此，我们不能将一个内置指针隐式转换为一个智能指针，必须使用直接初始化形式来初始化一个智能指针

```c++
shared_ptr<int> p2(new int(42));

shared_ptr<int> p3 = new int(1024); // 错误，必须使用直接初始化形式

// 不要混用普通指针和智能指针

void process(shared_ptr<int> ptr)
{
    // do something
} // ptr离开作用域，被销毁

shared_ptr<int> p(new int(42));
process(p);
int i = *p; // 正确：引用计数值为1

int *x(new int(32));
process(x); // 错误：无法将int*转换成shared_ptr<int>
process(shared_ptr<int>(x)); // 合法，但内存会被释放
int j = *x; // x是一个空悬指针

shared_ptr<int> sp(new int(42));
int *q = sp.get(); // 正确：但使用q时要注意，不要让它管理的指针被释放
{
    // 未定义：两个独立的shared_ptr指向相同的内存
    shared_ptr<int> (q);
} // q被销毁，它指向的内存被释放
int foo = *p; // 未定义：p指向的内存已经被释放了
```

智能指针类型定义了一个名为 get 的函数，它返回一个内置指针，指向智能指针管理的对象。此函数是为了这样一种情况而设计的：我们需要向不能使用智能指针的代码传递一个内置指针。使用 get 返回的指针的代码不能 delete 此指针。

### 智能指针和异常

使用只能指针的基本规范：

- 不使用相同的内置指针值初始化（或 reset）多个智能指针。
- 不 delete get（）返回的指针。
- 不使用 get（）初始化或 reset 另一个智能指针。
- 如果你使用 get（）返回的指针，记住当最后一个对应的智能指针销毁后，你的指针就变为无效了。
- 如果你使用智能指针管理的资源不是 new 分配的内存，记住传递给它一个删除器。

### unique_ptr

### weak_ptr

## 动态数组

### new 和数组

```c++
typedef int arrT[42];
int *p = new arrT;
delete [] p;

unique_ptr<int[]> up(new int[10]);
up.release(); // 自动用delete[]销毁其指针

// 与unique_ptr不同，shared_ptr不直接支持管理动态数组。如果希望使用shared_ptr管理一个动态数组，必须提供自己定义的删除器
shared_ptr<int> sp(new int[10], [](int *p) {delete [] p;});
sp.reset(); // 调用提供的删除器
```

### allocator 类

## 习题集

### 以下代码执行的结果

```c++
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

1. 首先是一个直接的内存泄漏问题，r 和 q 一样都指向 42 的内存地址，而 r 中原来保存的地址——100 的内存再无指针管理，变成“孤儿内存”，从而造成内存泄漏。
2. 其次是一个“空悬指针”问题。由于 r 和 q 指向同一个动态对象，如果程序编写不当，很容易产生释放了其中一个指针，而继续使用另一个指针的问题。继续使用的指针指向的是一块已经释放的内存，是一个空悬指针，继续读写它指向的内存可能导致程序崩溃甚至系统崩溃的严重问题。

shared_ptr 则可很好地解决这些问题。首先，分配了两个共享的对象，分别由共享指针 p2 和 q2 指向，因此它们的引用计数均为 1。接下来，将 q2 赋予 r2。赋值操作会将 q2 指向的对象地址赋予 r2，并将 r2 原来指向的对象的引用计数减 1，将 q2 指向的对象的引用计数加 1。这样，前者的引用计数变为 0，其占用的内存空间会被释放，不会造成内存泄漏。而后者的引用计数变为 2，也不会因为 r2 和 q2 之一的销毁而释放它的内存空间，因此也不会造成空悬指针的问题。
