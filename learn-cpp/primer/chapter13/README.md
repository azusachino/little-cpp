# 拷贝控制

## 拷贝、赋值、销毁

### 拷贝构造函数

```c++
class Foo {
    public:
    Foo(); // 默认构造函数
    Foo(const Foo&); // 拷贝构造函数
}
```

如果我们没有为一个类定义拷贝构造函数，编译器会为我们定义一个。与合成默认构造函数不同，即使我们定义了其他构造函数，编译器也会为我们合成一个拷贝构造函数。

当使用直接初始化时，我们实际上是要求编译器使用普通的函数匹配来选择与我们提供的参数最匹配的构造函数。当我们使用拷贝初始化（copy
initialization）时，我们要求编译器将右侧运算对象拷贝到正在创建的对象中，如果需要的话还要进行类型转换。

```c++
string dots(10, '.'); // 直接初始化
string s(dots); // 直接初始化
string s2 = dots; // 拷贝初始化
string null_book = "897893432"; // 拷贝初始化
string nines = string(100, '9'); // 拷贝初始化
```

- 将一个对象作为实参传递给一个非引用类型的形参
- 从一个返回类型为非引用类型的函数返回一个对象
- 用花括号列表初始化一个数组中的元素或一个聚合类中的成员

### 析构函数

无论何时一个对象被销毁，就会自动调用其析构函数：

- 变量在离开其作用域时被销毁。
- 当一个对象被销毁时，其成员被销毁。
- 容器（无论是标准库容器还是数组）被销毁时，其元素被销毁。
- 对于动态分配的对象，当对指向它的指针应用 delete 运算符时被销毁。
- 对于临时对象，当创建它的完整表达式结束时被销毁。

### 三/五法则

有三个基本操作可以控制类的拷贝操作：拷贝构造函数、拷贝赋值运算符和析构函数。而且，在新标准下，一个类还可以定义一个移动构造函数和一个移动赋值运算符

### 使用=default

```c++
class SalesData {
    public:
    SalesData() = default;
    SalesData(const SalesData&) = default;
    SalesData& operator=(const SalesData &);
    ~SalesData() = default;
}
```

### 阻止拷贝

```c++
struct NoCopy {
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;
    NoCopy &operator=(const NoCopy&);

    ~NoCopy() = default;
}
```

析构函数不能是删除的成员

合成的拷贝控制成员可能是删除的

- 如果类的某个成员的析构函数是删除的或不可访问的（例如，是 private 的），则类的合成析构函数被定义为删除的。
- 如果类的某个成员的拷贝构造函数是删除的或不可访问的，则类的合成拷贝构造函数被定义为删除的。如果类的某个成员的析构函数是删除的或不可访问的，则类合成的拷贝构造函数也被定义为删除的。
- 如果类的某个成员的拷贝赋值运算符是删除的或不可访问的，或是类有一个 const 的或引用成员，则类的合成拷贝赋值运算符被定义为删除的。
- 如果类的某个成员的析构函数是删除的或不可访问的，或是类有一个引用成员，它没有类内初始化器，或是类有一个 const 成员，它没有类内初始化器且其类型未显式定义默认构造函数，则该类的默认构造函数被定义为删除的。

private 拷贝控制

## 拷贝控制和资源管理

### 行为像值的类

- 定义一个拷贝构造函数，完成 string 的拷贝，而不是拷贝指针
- 定义一个析构函数来释放 string
- 定义一个拷贝赋值运算符来释放对象当前的 string，并从右侧运算对象拷贝 string

```c++
class HasPtr {
public:
    HasPtr(const string &s = string()): ps(new string(s), i(0)) {}
    HasPtr(const HasPtr &p): ps(new string(p.ps)), i(p.i) {}
    HasPtr & operator=(const HasPtr &);
    ~HasPtr() {delete ps;}
private:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newP = new string(*rhs.ps); // 拷贝底层string
    delete ps; // 释放旧内存

    ps = newP; // 从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;
}
```

赋值运算符：如果将一个对象赋予它自身，赋值运算符必须能正确工作。大多数赋值运算符组合了析构函数和拷贝构造函数的工作。

### 行为像指针的类

```c++
class HasPtr {
public:
    HasPtr(const string &s = string()): ps(new string(s), i(0)), usage(new size_t(1)) {}
    HasPtr(const HasPtr &p): ps(new string(p.ps)), i(p.i), usage(p.usage) {++*usage;}
    HasPtr & operator=(const HasPtr &);
    ~HasPtr() {}
private:
    string *ps;
    int i;
    size_t *usage; // 用来记录有多少个对象共享*ps的成员
};

HasPtr::~HasPtr() {
    if (--*usage == 0) {
        delete ps;
        delete usage;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
   ++*rhs.usage;

   if (--*usage == 0) {
       delete ps;
       delete usage;
   }

    ps = rhs.ps; // 从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    usage = rhs.usage;
    return *this;
}
```

### 交换操作

```c++
class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
};

// 内置类型是没有特定版本的swap的，所以在本例中，对swap的调用会调用标准库std：：swap。
inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// 拷贝并交换
HasPtr& HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}
```

## 拷贝控制示例

message.h

## 动态内存管理类

str-ver.h

## 对象移动

很多情况下都会发生对象拷贝。在其中某些情况下，对象拷贝后就立即被销毁了。在这些情况下，移动而非拷贝对象会大幅度提升性能。

标准库容器、string和shared_ptr类既支持移动也支持拷贝。IO类和unique_ptr类可以移动但不能拷贝。

```c++
int i = 42;
int &r = i;
int &&rr = i; // 错误，不能将一个右值引用绑定到一个左值上
int &r2 = i*42; // 错误，i*42是一个右值
const int &r3 = i * 42;// 正确，可以将const引用绑定到右值上
int &&rr2 = i*42; // 正确，将rr2绑定到乘法结果上
```

左值持久，右值短暂

### 移动构造函数和移动赋值运算符

不抛出异常的移动构造函数和移动赋值运算符必须标记为noexcept。

移动后源对象必须可析构。

只有当一个类没有定义任何自己版本的拷贝控制成员，且类的每个非static数据成员都可以移动时，编译器才会为它合成移动构造函数或移动赋值运算符。编译器可以移动内置类型的成员。

- 与拷贝构造函数不同，移动构造函数被定义为删除的函数的条件是：有类成员定义了自己的拷贝构造函数且未定义移动构造函数，或者是有类成员未定义自己的拷贝构造函数且编译器不能为其合成移动构造函数。移动赋值运算符的情况类似。
- 如果有类成员的移动构造函数或移动赋值运算符被定义为删除的或是不可访问的，则类的移动构造函数或移动赋值运算符被定义为删除的。
- 类似拷贝构造函数，如果类的析构函数被定义为删除的或不可访问的，则类的移动构造函数被定义为删除的。
- 类似拷贝赋值运算符，如果有类成员是const的或是引用，则类的移动赋值运算符被定义为删除的。

```cpp
struct hasY {
    hasY() = default;
    hasY(hasY&&) = default;
    Y mem; // hasY有一个删除的移动构造函数
}
hasY hy, hy2 = std::move(hy); // 错误，移动构造函数是删除的
```

移动右值、拷贝左值，但如果没有移动构造函数，右值也被拷贝

### 右值引用和成员函数

允许移动的成员函数通常使用与拷贝/移动构造函数和赋值运算符相同的参数模式——一个版本接受一个指向const的左值引用，第二个版本接受一个指向非const的右值引用。

## 习题集

### 拷贝构造函数是什么？

如果构造函数的第一个参数是自身类类型的引用，且所有其他参数（如果有的话）都有默认值，则此构造函数是拷贝构造函数。拷贝构造函数在以下几种情况下会被使用：

●拷贝初始化（用=定义变量）。

●将一个对象作为实参传递给非引用类型的形参。

●一个返回类型为非引用类型的函数返回一个对象。

●用花括号列表初始化一个数组中的元素或一个聚合类中的成员。

●初始化标准库容器或调用其insert/push操作时，容器会对其元素进行拷贝初始化。

## 下面的代码段会发生几次析构函数调用？

```c++
bool fcn(const Sales_data *trans, Sales_data accum) {
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
```

这段代码中会发生三次析构函数调用：

1．函数结束时，局部变量item1的生命期结束，被销毁，Sales_data的析构函数被调用。

2．类似的，item2在函数结束时被销毁，Sales_data的析构函数被调用。

3．函数结束时，参数accum的生命期结束，被销毁，Sales_data的析构函数被调用。