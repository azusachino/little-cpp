# C++Primer Chapter03

## 命名空间的using声明

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

## 标准类库string

标准库类型string表示可变长的字符序列，使用string类型必须首先包含string头文件。作为标准库的一部分，string定义在命名空间std中。

```c++
#include <string>
using std::string;
```

### 定义和初始化string对象

```c++
string s1; // default initialization, with an empty string ""
string s2 = s1; // s2 is the replica of s1
string s3 = "hi"; // s3 is the replica of "hi"
string s4(10, 'c'); // s4 is cccccccccc
```

如果使用等号（=）初始化一个变量，实际上执行的是拷贝初始化（copy initialization），编译器把等号右侧的初始值拷贝到新创建的对象中去。与之相反，如果不使用等号，则执行的是直接初始化（direct initialization）。

### 操作string对象

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

### 处理string对象中的字符

```c++
string s("some string");
if (!s.empty()){
    s[0] = toupper(s[0]);
}
```

## 标准库类型vector

标准库类型vector表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有一个与之对应的索引，索引用于访问对象。因为vector“容纳着”其他对象，所以它也常被称作容器（container）。

```c++
#include <vector>
using std::vector;
```

vector是模板而非类型，由vector生成的类型必须包含vector中元素的类型，例如`vector<int>`。

模板本身不是类或函数，相反可以将模板看作为编译器生成类或函数编写的一份说明。编译器根据模板创建类或函数的过程称为实例化（instantiation），当使用模板时，需要指出编译器应把类或函数实例化成何种类型。

### 定义和初始化vector对象

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

### 向vector对象中添加元素

```c++
v.empty()
v.size()
v.push_back()
v[n]
```

## 迭代器介绍

这些类型都拥有名为begin和end的成员，其中begin成员负责返回指向第一个元素（或第一个字符）的迭代器。end成员返回的迭代器常被称作尾后迭代器（off-the-end iterator）或者简称为尾迭代器（end iterator）。特殊情况下如果容器为空，则begin和end返回的是同一个迭代器。

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

某些对vector对象的操作会使迭代器失效

## 数组

## 习题集

string表示可变长字符串，它的初始化方式分为两种：直接初始化和拷贝初始化。如果要处理string中的单个字符，我们可以使用C++11新定义的范围for语句，也可以使用下标运算符执行随机访问。

vector表示对象的集合，其中所有对象的类型相同。如果要向vector对象中添加元素，必须使用push_back()函数，不允许使用下标形式添加元素。

除此之外，本章还介绍了迭代器和数组。迭代器提供与指针功能类似的间接访问操作，迭代器可以执行解引用、与整数相加、比较、两个整数相减等操作，但是不能直接把两个迭代器相加。  
与vector一样，数组也表示同类型对象的集合，但是vector的长度不固定，而数组的容量是固定不变的。在C++11新标准下，我们可以使用与迭代器类似的begin和end函数确定数组的边界。

### string的输入运算符和getline函数是如何处理空白字符
