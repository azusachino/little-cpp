# 泛型算法

顺序容器只定义了很少的操作：在多数情况下，我们可以添加和删除元素、访问首尾元素、确定容器是否为空以及获得指向首元素或尾元素之后位置的迭代器。

查找特定元素、替换或删除一个特定值、重排元素顺序等。

## 概述

大多数算法都定义在头文件 algorithm 中。标准库还在头文件 numeric 中定义了一组数值泛型算法。

```c++
int val = 42;
auto result = find(vec.cbegin(), vec.cend(), val); // returns iterator

if (result == c.cend()) {
    cout << "not find" << endl;
}

// 使用标准库begin和end函数来获得指向ia中首元素和尾元素之后位置的指针
int ia[] = {1,2,3,4,5};
int ival = 3;
int *result = find(begin(ia), end(ia), ival);
```

泛型算法本身不会执行容器的操作，它们只会运行于迭代器之上，执行迭代器的操作。泛型算法运行于迭代器之上而不会执行容器操作的特性带来了一个令人惊讶但非常必要的编程假定：算法永远不会改变底层容器的大小。算法可能改变容器中保存的元素的值，也可能在容器内移动元素，但永远不会直接添加或删除元素。

## 初识泛型算法

### 只读算法

find, accumulate, equal

### 写容器元素的算法

fill, fill_n, back_inserter, copy, replace

### 重排容器元素的算法

sort, unique

## 定制操作

### 向算法传递函数

### lambda 表达式

```c++
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
}
```

可调用对象：函数、函数指针、重载了函数调用运算符的类和 lambda 表达式

一个 lambda 表达式表示一个可调用的代码单元。我们可以将其理解为一个未命名的内联函数。与任何函数类似，一个 lambda 具有一个返回类型、一个参数列表和一个函数体。但与函数不同，lambda 可能定义在函数内部。一个 lambda 表达式具有如 `[capture list] (parameter list) -> return type { function body }`

capture list（捕获列表）是一个 lambda 所在函数中定义的局部变量的列表（通常为空）；return type、parameter list 和 function body 与任何普通函数一样，分别表示返回类型、参数列表和函数体。

```c++
auto isShorter = [] (const string &a, const string &b) -> bool {return a.size() < b.size();};

stable_sort(words.begin(), words.end(), isShorter);

auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() > sz; });

for_each(wc, words.end(), [](const string &a) {cout << s << endl;})
```

捕获列表只用于局部非 static 变量，lambda 可以直接使用局部 static 变量和在它所在函数之外声明的名字。

### lambda 捕捉和返回

与参数不同，被捕获的变量的值是在 lambda 创建时拷贝，而不是调用时拷贝：

```c++
// 值捕获
void fun1() {
    size_t v1 = 42;
    // 将v1拷贝到名为f的可调用对象
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f(); // j == 42：f保存了创建lambda时v1的拷贝
}

// 引用捕获
void fun2() {
    size_t v1 = 45;
    auto f2 = [&v1] { return v1; };
    v1 = 0;
    auto j = f(); // j == 0
}

void fun3() {
    size_t v1 = 31;
    auto f = [=] () mutable { return ++v1; };
    v1 = 0;
    auto j = f(); // j == 32
}
```

如果我们采用引用方式捕获一个变量，就必须确保被引用的对象在lambda执行的时候是存在的。

### 参数绑定

可以将bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表。 `auto newCallable = bind(callable, arg_list);`

arg_list中的参数可能包含形如_n的名字，其中n是一个整数。这些参数是“占位符”，表示newCallable的参数，它们占据了传递给newCallable的参数的“位置”。数值n表示生成的可调用对象中参数的位置：_1为newCallable的第一个参数，_2为第二个参数，依此类推。

```c++
auto check6 = bind(check_size, _1, 6);
string s = "hello";
bool b1 = check6(s);
```

名字_n都定义在一个名为placeholders的命名空间中，而这个命名空间本身定义在std命名空间中。

## 再探迭代器

- 插入迭代器（insert iterator）：这些迭代器被绑定到一个容器上，可用来向容器插入元素。
- 流迭代器（stream iterator）：这些迭代器被绑定到输入或输出流上，可用来遍历所关联的IO流。
- 反向迭代器（reverse iterator）：这些迭代器向后而不是向前移动。除了forward_list之外的标准库容器都有反向迭代器。
- 移动迭代器（move iterator）：这些专用的迭代器不是拷贝其中的元素，而是移动它们。

### 插入迭代器

- back_inserter创建一个使用push_back的迭代器。
- front_inserter创建一个使用push_front的迭代器。
- inserter创建一个使用insert的迭代器。此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器所表示的元素之前。

### iostream迭代器

istream_iterator读取输入流，ostream_iterator向一个输出流写数据。

```c++
istream_iterator<int> int_it(cin);
istream_iterator<int> int_eof;
ifstream in("afile");
istream_iterator<string> str_it(in); // 从afile读取字符串
```

### 反向迭代器

反向迭代器就是在容器中从尾元素向首元素反向移动的迭代器。对于反向迭代器，递增（以及递减）操作的含义会颠倒过来。递增一个反向迭代器（++it）会移动到前一个元素；递减一个迭代器（--it）会移动到下一个元素。

## 泛型算法结构

### 输入迭代器

输入迭代器（input iterator）：可以读取序列中的元素。一个输入迭代器必须支持

- 用于比较两个迭代器的相等和不相等运算符（==、！=）
- 用于推进迭代器的前置和后置递增运算（++）
- 用于读取元素的解引用运算符（*）；解引用只会出现在赋值运算符的右侧
- 箭头运算符（->），等价于（*it）.member，即，解引用迭代器，并提取对象的成员

### 输出迭代器

输出迭代器（output iterator）：可以看作输入迭代器功能上的补集——只写而不读元素。输出迭代器必须支持

- 用于推进迭代器的前置和后置递增运算（++）
- 解引用运算符（*），只出现在赋值运算符的左侧（向一个已经解引用的输出迭代器赋值，就是将值写入它所指向的元素）

### 前向迭代器

前向迭代器（forward iterator）：可以读写元素。这类迭代器只能在序列中沿一个方向移动。前向迭代器支持所有输入和输出迭代器的操作，而且可以多次读写同一个元素。因此，我们可以保存前向迭代器的状态，使用前向迭代器的算法可以对序列进行多遍扫描。算法replace要求前向迭代器，forward_list上的迭代器是前向迭代器。

### 双向迭代器

双向迭代器（bidirectional iterator）：可以正向/反向读写序列中的元素。除了支持所有前向迭代器的操作之外，双向迭代器还支持前置和后置递减运算符（--）。算法reverse要求双向迭代器，除了forward_list之外，其他标准库都提供符合双向迭代器要求的迭代器。

### 随机访问迭代器

随机访问迭代器（random-access iterator）：提供在常量时间内访问序列中任意元素的能力。此类迭代器支持双向迭代器的所有功能

- 用于比较两个迭代器相对位置的关系运算符（<、<=、>和>=）
- 迭代器和一个整数值的加减运算（+、+=、-和-=），计算结果是迭代器在序列中前进（或后退）给定整数个元素后的位置
- 用于两个迭代器上的减法运算符（-），得到两个迭代器的距离
- 下标运算符（iter[n]），与＊（iter[n]）等价

### 算法形参模式

```c++
alg(beg, end, args);
alg(beg, end, dest, args);
alg(beg, end, beg2, args);
alg(beg, end, beg2, end2, args);
```

### 算法命名规范

_if：接受一个元素值的算法通常有另一个不同名的（不是重载的）版本，该版本接受一个谓词（参见10.3.1节，第344页）代替元素值。接受谓词参数的算法都有附加的_if前缀

_copy：将元素写到一个指定的输出目的位置。

## 习题集

### 标准库算法不会改变它们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？

严格来说，标准库算法根本不知道有“容器”这个东西。它们只接受迭代器参数，运行于这些迭代器之上，通过这些迭代器来访问元素。

标准库算法从来不直接操作容器，它们只操作迭代器，从而间接访问容器。能不能插入和删除元素，不在于算法，而在于传递给它们的迭代器是否具有这样的能力。
