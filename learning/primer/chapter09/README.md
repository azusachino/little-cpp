# 顺序容器

## 顺序容器概述

- 向容器添加或从容器中删除元素的代价
- 非顺序访问容器中元素的代价

vector, deque, list, foward_list, array, string

选择容器的基本原则：

- 除非你有很好的理由选择其他容器，否则应使用 vector。
- 如果你的程序有很多小的元素，且空间的额外开销很重要，则不要使用 list 或 forward_list。
- 如果程序要求随机访问元素，应使用 vector 或 deque。
- 如果程序要求在容器的中间插入或删除元素，应使用 list 或 forward_list。
- 如果程序需要在头尾位置插入或删除元素，但不会在中间位置进行插入或删除操作，则使用 deque。

## 容器库概览

### 迭代器

一个迭代器范围（iterator range）由一对迭代器表示，两个迭代器分别指向同一个容器中的元素或者是尾元素之后的位置（one past the last element）。【左闭右开】

使用左闭合范围蕴含的编程假定：

- 如果 begin 与 end 相等，则范围为空
- 如果 begin 与 end 不等，则范围至少包含一个元素，且 begin 指向该范围中的第一个元素
- 我们可以对 begin 递增若干次，使得 begin==end

### 容器类型成员

通过类型别名，我们可以在不了解容器中元素类型的情况下使用它。如果需要元素类型，可以使用容器的 value_type。如果需要元素类型的一个引用，可以使用 reference 或 const_reference。

### begin&end 成员

```c++
list<string> a = {"milton", "shakespeare", "austen"};
auto it1 = a.begin();
auto it2 = a.rbegin(); // reverse_iterator
auto it3 = a.cbegin();
auto it4 = a.crbegin(); // const_reverse_iterator
```

### 容器定义和初始化

每个容器类型都定义了一个默认构造函数。除 array 之外，其他容器的默认构造函数都会创建一个指定类型的空容器，且都可以接受指定容器大小和元素初始值的参数。

```c++
list<string> authors = {"a", "b", "c"};
vector<const char*> articles = {"o", "p", "q"};

list<string> list2(authors); // 正确：类型匹配
deque<string> authList(authors); // 错误：容器类型不匹配
vector<string> words(articles); // 错误：容器类型必须匹配

forward_list<string> words(articles.begin(), articles.end()); // 正确：可以将const char*转换成string
```

当将一个容器初始化为另一个容器的拷贝时，两个容器的容器类型和元素类型都必须相同。

为了使用 array 类型，必须同时指定元素类型和大小：`array<int, 42>`

### 赋值和 swap

与内置数组不同，标准库 array 类型允许赋值。赋值号左右两边的运算对象必须具有相同的类型：

```c++
array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
array<int, 10> a2 = {0}; // 所有元素均为0
a1 = a2; // 替换a1中的元素
a2 = {0}; // 错误：不能将一个花括号列表赋予数组
```

赋值运算符要求左边和右边的运算对象具有相同的类型。它将右边运算对象中所有元素拷贝到左边运算对象中。顺序容器（array 除外）还定义了一个名为 assign
的成员，允许我们从一个不同但相容的类型赋值，或者从容器的一个子序列赋值。assign 操作用参数所指定的元素（的拷贝）替换左边容器中的所有元素。

```c++
list<string> names;
vector<const char*> old_style;

names = old_style; // 类型不匹配
names.assign(old_style.cbegin(), old_style.cend());
```

swap 操作交换两个相同类型容器的内容。调用 swap 之后，两个容器中的元素将会交换：

```c++
vector<string> svec1(10);
vector<string> svec2(24);
swap(svec1, svec2);
```

### 容器大小操作

成员函数 size（参见 3.2.2 节，第 78 页）返回容器中元素的数目；empty 当 size 为 0 时返回布尔值 true，否则返回 false；max_size
返回一个大于或等于该类型容器所能容纳的最大元素数的值。forward_list 支持 max_size 和 empty，但不支持 size。

### 关系运算符

每个容器类型都支持相等运算符（==和！=）；除了无序关联容器外的所有容器都支持关系运算符（>、>=、<、<=）。关系运算符左右两边的运算对象必须是相同类型的容器，且必须保存相同类型的元素。

运算符的工作方式：

- 如果两个容器具有相同大小且所有元素都两两对应相等，则这两个容器相等；否则两个容器不等。
- 如果两个容器大小不同，但较小容器中每个元素都等于较大容器中的对应元素，则较小容器小于较大容器。
- 如果两个容器都不是另一个容器的前缀子序列，则它们的比较结果取决于第一个不相等的元素的比较结果。

```c++
vector<int> v1 = {1,3,5,7,9,12};
vector<int> v2 = {1,3,9};
vector<int> v3 = {1,3,5,7};
vector<int> v4 = {1,3,5,7,9,12};

v1 < v2; // true: v1和v2在元素[2]处不同，v1[2] < v2[2]
v1 < v3; // false
v1 == v4; // true
v1 == v2; // false:v2的元素比v1少
```

## 顺序容器操作

除 array 外，所有标准库容器都提供灵活的内存管理。在运行时可以动态添加或删除元素来改变容器大小。

每个`insert`
函数都接受一个迭代器作为其第一个参数。迭代器指出了在容器中什么位置放置新元素。它可以指向容器中任何位置，包括容器尾部之后的下一个位置。由于迭代器可能指向容器尾部之后不存在的元素的位置，而且在容器开始位置插入元素是很有用的功能，所以
insert 函数将元素插入到迭代器所指定的位置之前。

```c++
vector<string> svec;
list<string> slist;

slist.insert(slist.begin(), "Hello");
slist.push_front("Hello");

// vector不支持push_front
svec.insert(svec.begin(), "Hello");

vector<string> v = {"a", "b", "c"};
v.insert(v.begin(), v.end()-2, v.end());
v.insert(v.end(), {"e", "f", "g"});

v.insert(v.begin(), v.end(), v.end()); // runtime_error,迭代器表示要拷贝的范围，不能指向与目的位置相同的容器

list<string> lst;
auto iter = lst.begin();
while (cin >> word) {
    iter = lst.insert(iter, word);
}
```

### 访问元素

包括 array 在内的每个顺序容器都有一个 front 成员函数，而除 forward_list 之外的所有顺序容器都有一个 back 成员函数，这两个操作分别返回首元素和尾元素的引用。

提供快速随机访问的容器（string、vector、deque 和 array）也都提供下标运算符。

### 删除元素

pop_front, pop_back, erase

### forward_list

forward_list 并未定义 insert、emplace 和 erase，而是定义了名为 insert_after、emplace_after 和 erase_after 的操作。

### 改变容器大小

使用 resize 来增大或缩小容器

```c++
list<int> ilist(10, 42);
ilist.resize(15); // 在后方添加5个0
ilist.resize(25, -1); // 在后方添加10个-1
ilist.resize(5); // 从末尾删除20个元素
```

### 容器操作可能使迭代器失败

向容器添加元素后：

- 如果容器是 vector 或 string，且存储空间被重新分配，则指向容器的迭代器、指针和引用都会失效。如果存储空间未重新分配，指向插入位置之前的元素的迭代器、指针和引用仍有效，但指向插入位置之后元素的迭代器、指针和引用将会失效。
- 对于 deque，插入到除首尾位置之外的任何位置都会导致迭代器、指针和引用失效。如果在首尾位置添加元素，迭代器会失效，但指向存在的元素的引用和指针不会失效。
- 对于 list 和 forward_list，指向容器的迭代器（包括尾后迭代器和首前迭代器）、指针和引用仍有效。

删除一个元素后：

- 对于 list 和 forward_list，指向容器其他位置的迭代器（包括尾后迭代器和首前迭代器）、引用和指针仍有效。
- 对于 deque，如果在首尾之外的任何位置删除元素，那么指向被删除元素外其他元素的迭代器、引用或指针也会失效。如果是删除 deque 的尾元素，则尾后迭代器也会失效，但其他迭代器、引用和指针不受影响；如果是删除首元素，这些也不会受影响。
- 对于 vector 和 string，指向被删元素之前元素的迭代器、引用和指针仍有效。注意：当我们删除元素时，尾后迭代器总是会失效。

## vector 对象是如何增长的

理解 capacity 和 size 的区别非常重要。容器的 size 是指它已经保存的元素的数目；而 capacity 则是在不分配新的内存空间的前提下它最多可以保存多少元素。

## 额外的 string 操作

### 构造 string 的其他方法

### string 搜索操作

string 类提供了 6 个不同的搜索函数，每个函数都有 4 个重载版本。表 9.14 描述了这些搜索成员函数及其参数。每个搜索操作都返回一个 string：：size_type 值，表示匹配发生位置的下标。如果搜索失败，则返回一个名为
string：：npos 的 static 成员。标准库将 npos 定义为一个 const string：：size_type 类型，并初始化为值-1。由于 npos 是一个 unsigned 类型，此初始值意味着 npos 等于任何
string 最大的可能大小。

## 容器适配器

标准库还定义了三个顺序容器适配器：stack、queue 和 priority_queue。适配器（adaptor）是标准库中的一个通用概念。容器、迭代器和函数都有适配器。

默认情况下，stack 和 queue 是基于 deque 实现的，priority_queue 是在 vector 之上实现的。

## 习题集

### 6 种创建和初始化 vector 对象的方法

1. `vector<int> ilist1;` // 默认初始化，vector 为空——size 返回 0，表明容器中尚未有元素；capacity 返回
   0，意味着尚未分配存储空间。这种初始化方式适合于元素个数和值未知，需要在程序运行中动态添加的情况。
2. `vector<int> ilist2(ilist);` // ilist2 初始化为 ilist 的拷贝，ilist 必须与 ilist2 类型相同，即也是 int 的 vector 类型，ilist2 将具有与 ilist
   相同的容量和元素。
3. `vector<int> ilist = {1, 2, 3.0, 4, 5, 6, 7};` // ilist 初始化为列表中元素的拷贝，列表中的元素类型必须与 ilist
   的元素类型相容，在本例中必须是与整型相容的数值类型。对于整型，会直接拷贝其值，对于其他类型则需进行类型转换（如 3.0 转换为 3）。这种初始化方式适合元素数量和值预先可知的情况。
4. `vector<int> ilist3(ilist.begin()+2, ilist.end()-1);` // ilist3 初始化为两个迭代器指定范围中的元素的拷贝，范围中的元素类型必须与 ilist3 的元素类型相容，在本例中
   ilist3 被初始化为{3, 4, 5, 6}。注意，由于只要求范围中元素类型与待初始化的容器的元素类型相容，因此，迭代器来自于不同类型的容器是可能的，例如，用一个 double 的 list 的范围来初始化 ilist3
   是可行的。另外，由于构造函数只是读取范围中的元素并进行拷贝，因此使用普通迭代器还是 const 迭代器来指出范围并无区别。这种初始化方法特别适合于获取一个序列的子序列。
5. `vector<int> ilist4(7);` // 默认值初始化，ilist4 中将包含 7 个元素，每个元素进行缺省的值初始化，对于 int，也就是被赋值为 0，因此 ilist4 被初始化为包含 7 个
   0。当程序运行初期元素大致数量可预知，而元素的值需动态获取时，可采用这种初始化方式。
6. `vector<int> ilist5(7, 3);` // 指定值初始化，ilist5 被初始化为包含 7 个值为 3 的 int。

### 如何从一个`list<int>`初始化一个`vector<double>`？从一个`vector<int>`又该如何创建？

由于`list<int>`与`vector<double>`是不同的容器类型，因此无法采用容器拷贝初始化方式。但前者的元素类型是 int，与后者的元素类型 double
是相容的，因此可以采用范围初始化方式来构造一个`vector<double>`，令它的元素值与`list<int>`完全相同。
