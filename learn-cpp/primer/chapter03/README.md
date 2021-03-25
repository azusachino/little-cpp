# 字符串、向量和数组

## 命名空间的 using 声明

```c++
// 可以直接访问命名空间中的名字
// using namespace::name;

#include <iostream>

// 每个名字都需要独立的using声明
using std::cin;

int main() {
    int i;
    cin >> i; // 正确：cin和std::cin含义相同
    cout << i; // 错误：没有对应的using声明
    std::cout << i; // 正确：显式使用std::cout
    return 0;
}
```

## 标准类库 string

标准库类型 string 表示可变长的字符序列，使用 string 类型必须首先包含 string 头文件。作为标准库的一部分，string 定义在命名空间 std 中。

```c++
#include <string>
using std::string;
```

### 定义和初始化 string 对象

```c++
string s1; // default initialization, with an empty string ""
string s2 = s1; // s2 is the replica of s1
string s3 = "hi"; // s3 is the replica of "hi"
string s4(10, 'c'); // s4 is cccccccccc
```

如果使用等号（=）初始化一个变量，实际上执行的是拷贝初始化（copy initialization），编译器把等号右侧的初始值拷贝到新创建的对象中去。与之相反，如果不使用等号，则执行的是直接初始化（direct initialization）。

### 操作 string 对象

```c++
os << s; // 将s写到输出流os中，并返回os
is >> s; // 从is中读取字符串赋给s，字符串以空白分隔，返回is
getline(is, s); // 从is中读取一行赋给s，返回is
s.empty(); // s为空返回true
s.size();
s[n];
s1+s2;
s1 = s2;
s1 == s2;
<,<=,>,>=

// 读取未知数量的string对象
string word;
while (cin >> word) {
    cout << word << endl;
}

// 使用getline读取一整行
string line;
while(getline(cin, line)) {
    cout << line << endl;
}
```

### 处理 string 对象中的字符

```c++
string s("some string");
if (!s.empty()){
    s[0] = toupper(s[0]);
}
```

## 标准库类型 vector

标准库类型 vector 表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有一个与之对应的索引，索引用于访问对象。因为 vector“容纳着”其他对象，所以它也常被称作容器（container）。

```c++
#include <vector>
using std::vector;
```

vector 是模板而非类型，由 vector 生成的类型必须包含 vector 中元素的类型，例如`vector<int>`。

模板本身不是类或函数，相反可以将模板看作为编译器生成类或函数编写的一份说明。编译器根据模板创建类或函数的过程称为实例化（instantiation），当使用模板时，需要指出编译器应把类或函数实例化成何种类型。

### 定义和初始化 vector 对象

```c++
vector<T> v1; // v1是一个空vector，它潜在的元素是T类型的，执行默认初始化
vector<T> v2(v1); // v2中包含有v1所有元素的副本
vector<T> v2 = v1; // 等价于v2(v1)
vector<T> v3(n, val); // v3包含了n个重复的元素val
vector<T> v4(n); // v4包含了n个重复地执行了值初始化地对象
vector<T> v5{a,b,c...} == vector<T> v5 = {a,b,c...}
```

### 初始化相关示例

```c++
#include <iostream>
#include <vector>
using std::vector

vector<string> svec;
vector<string> articles = {"a", "b", "c"};
vector<string> sv(10, "hi"); // 10个string的vector
```

### 向 vector 对象中添加元素

```c++
v.empty()
v.size()
v.push_back()
v[n]
```

## 迭代器介绍

这些类型都拥有名为 begin 和 end 的成员，其中 begin 成员负责返回指向第一个元素（或第一个字符）的迭代器。end 成员返回的迭代器常被称作尾后迭代器（off-the-end iterator）或者简称为尾迭代器（end iterator）。特殊情况下如果容器为空，则 begin 和 end 返回的是同一个迭代器。

```c++
string s("some string")
if (s.begin() != s.end()) {
    auto it = s.begin();
    *it = toupper(*it);
}
```

### 迭代器类型

```c++
vector<int>::iterator it; // it能读写vector<int>的元素
string::iterator it2; // it2能读写string对象中的字符
vector<int>::const_interator; string::const_iterator; // 只能读取
```

### 结合解引用和成员访问操作

```c++
// 对于一个由字符串组成的vector对象来说，要想检查其元素是否为空，令it是该vector对象的迭代器，只需检查it所指字符串是否为空就可以了
(*it).empty(); // 解引用it，然后调用结果对象的empty成员
*it.empty(); // 错误，试图访问it的名为empty的成员，但it是一个迭代器，没有empty成员

for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
    cout << *it << endl;
}
```

某些对 vector 对象的操作会使迭代器失效

## 数组

### 定义和初始化内置数组

数组的声明形如 a[d]，其中 a 是数组的名字，d 是数组的维度。维度说明了数组中元素的个数，因此必须大于 0。数组中元素的个数也属于数组类型的一部分，编译的时候维度应该是已知的。也就是说，维度必须是一个常量表达式

```c++
unsigned cnt = 42;
constexpr unsigned sz = 42;
int arr[10];
int *pArr[sz];
string bad[cnt]; // cnt不是常量表达式
string strings[get_size()]; // 当get_size是constexpr时正确

// 显式初始化数组元素
const unsigned sz = 3;
int a1[sz] = {0,1,2};
int a2[] = {0,1,2};
int a3[6] = {0,1,2}; // equals to {0,1,2,0,0}, default init value
string a4[3] = {"hi", "bye"} // equals to {"hi", "bye", ""}
int a5[2] = {1,2,3} // wrong expr, oversized

// speciality of string array
char c1[] = {'C', '+'}; // size: 4
char c2[] = {'C', '+', '\0'} // with '\0' , size: 4
char c3[] = "C+"; // automatic add '\0' to the end, size: 4
const char c4[6] = "Daniel"; // wrong expr, no space for extra '\0'

// copy and apply not allowed
int b[] = {0,1,2}
int b2[] = b; // not allowed
bc = a; // not allowed
```

### Complicate Array

```c++
int *ptrs[10]; // ptrs is a array including 10 int pointers
int &refs[10] = /*?*/; // wrong expr, no ref array
int (*Parry)[10] = &arr; // Parry point to a array including 10 int
int (&arrRef)[10] = arr; // arrRef refer to a array including 10 int

int *(&array)[10] = ptrs; // array refer to a array which including 10 pointers
```

### Array & Pointer

在大多数表达式中，使用数组类型的对象其实是使用一个指向该数组首元素的指针。

```c++
string nums[] = {"one", "two", "three"};
string *p = &nums[0];
string *p2 = nums; // equals to p2 = &nums[0]

// pointer is also a iterator
int arr[] = {0,1,2,3,4};
int *p = arr;
int *e = &arr[5]; // 获取数组尾元素之后的那个不存在元素的地址，容易出错
for (; p != e; ++p){
    cout << *p << endl;
}

// c++ 11 with begin() and end()
int arr2[] = {0,1,2,3,4};
int *beg = begin(arr2); // 指向首元素
int *end = end(arr2); // 指向尾元素的下一位置
while (beg!=end && *beg >= 0) {
    ++beg;
}
```

## 多维数组

严格来说，C++语言中没有多维数组，通常所说的多维数组其实是数组的数组。

```c++
int ia[3][4] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}
};
// ia和ib是等价的，暗示了在内存中的存储方式
int ib[3][4] = {
    0,1,2,3,4,5,6,7,8,9,10,11
};

// 因为要改变元素的值，所以得把控制变量row和col声明成引用类型
size_t cnt = 0;
for (auto &row : ia) { // row的类型是含有四个整数的数组的引用
    for (auto &col : row) { // col的类型是整数的引用
        col = cnt;
        ++cnt;
    }
}

for (const auto &row :ia) {
    for (auto col : row) {
        cout << col << endl;
    }
}

// 无法通过编译
for(auto row : ia) {
    for (auto col : row) {

    }
}
// 程序将无法通过编译。这是因为，像之前一样第一个循环遍历ia的所有元素，注意这些元素实际上是大小为4的数组。因为row不是引用类型，所以编译器初始化row时会自动将这些数组形式的元素（和其他类型的数组一样）转换成指向该数组内首元素的指针。这样得到的row的类型就是int＊，显然内层的循环就不合法了，编译器将试图在一个int＊内遍历，这显然和程序的初衷相去甚远。
int ia[3][4];
int (*p)[4] = ia; // p指向含有4个整数的数组
p = &ia[2]; // p指向ia的尾元素

for (auto p = ia; p != ia+3; ++p) {
    for (auto q = *p; q!=*p+4;++q) {
        cout << *q << '' << endl;
    }
}

for (auto p = begin(ia); p != end(ia); ++p) {
    for (auto q = begin(*p); q != end(*p); ++q) {
        cout << *q << " " << endl;
    }
}
```

## 小结

string 和 vector 是两种最重要的标准库类型。string 对象是一个可变长的字符序列，vector 对象是一组同类型对象的容器。

迭代器允许对容器中的对象进行间接访问，对于 string 对象和 vector 对象来说，可以通过迭代器访问元素或者在元素间移动。

数组和指向数组元素的指针在一个较低的层次上实现了与标准库类型 string 和 vector 类似的功能。一般来说，应该优先选用标准库提供的类型，之后再考虑 C++语言内置的低层的替代品数组或指针。

## 习题集

string 表示可变长字符串，它的初始化方式分为两种：直接初始化和拷贝初始化。如果要处理 string 中的单个字符，我们可以使用 C++11 新定义的范围 for 语句，也可以使用下标运算符执行随机访问。

vector 表示对象的集合，其中所有对象的类型相同。如果要向 vector 对象中添加元素，必须使用 push_back()函数，不允许使用下标形式添加元素。

除此之外，本章还介绍了迭代器和数组。迭代器提供与指针功能类似的间接访问操作，迭代器可以执行解引用、与整数相加、比较、两个整数相减等操作，但是不能直接把两个迭代器相加。  
与 vector 一样，数组也表示同类型对象的集合，但是 vector 的长度不固定，而数组的容量是固定不变的。在 C++11 新标准下，我们可以使用与迭代器类似的 begin 和 end 函数确定数组的边界。

### string 的输入运算符和 getline 函数是如何处理空白字符

标准库 string 的输入运算符自动忽略字符串开头的空白（包括空格符、换行符、制表符等），从第一个真正的字符开始读起，直到遇见下一处空白为止。

如果希望在最终的字符串中保留输入时的空白符，应该使用 getline 函数代替原来的>>运算符，getline 从给定的输入流中读取数据，直到遇到换行符为止，此时换行符也被读取进来，但是并不存储在最后的字符串中。

参见`read-blank.cc`

### 初始化 vector

```c++
// 1. 定义空vector，依次添加元素
vector<int> v1;
for(int i = 0; i < 3; i++) {
    v1.push_back(42);
}

// 2. 列表初始化
vector<int> v2 = {42,42,42};

// 3. 用括号初始化
vector<int> v3{42,42,42};

// 4. 使用参数指定元素个数和重复的值
vector<int> v4(3, 42);

// 5. 先指定元素个数，再利用范围for赋值
vector<int> v5(10);
for (auto &i : v5) {
    i = 42;
}
```

### 将两个指针相加不但是非法的，而且也没什么意义。请问为什么两个指针相加没什么意义？

指针也是一个对象，与指针相关的属性有 3 个，分别是指针本身的值（value）、指针所指的对象（content）以及指针本身在内存中的存储位置（address）。它们的含义分别是：

指针本身的值是一个内存地址值，表示指针所指对象在内存中的存储地址；指针所指的对象可以通过解引用指针访问；因为指针也是一个对象，所以指针也存储在内存的某个位置，它有自己的地址，这也是为什么有“指针的指针”的原因。

通过上述分析我们知道，指针的值是它所指对象的内存地址，如果我们把两个指针加在一起，就是试图把内存中两个对象的存储地址加在一起，这显然是没有任何意义的。与之相反，指针的减法是有意义的。如果两个指针指向同一个数组中的不同元素，则它们相减的结果表征了它们所指的元素在数组中的距离。
