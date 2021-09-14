# 函数

## 函数基础

一个典型的函数（function）定义包括以下部分：返回类型（return type）、函数名字、由 0
个或多个形参（parameter）组成的列表以及函数体。其中，形参以逗号隔开，形参的列表位于一对圆括号之内。函数执行的操作在语句块中说明，该语句块称为函数体（function body）。

- 函数调用完成两项工作：一是用实参初始化函数对应的形参，二是将控制权转移给被调用函数。
- return 语句的两项工作：一是返回 return 语句中的值，二是将控制权从被调函数转移回主调函数。

### 局部对象

- 名字的作用域是程序文本的一部分，名字在其中可见
- 对象的生命周期是程序执行过程中该对象存在的一段时间

局部静态对象在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止才被销毁。

### 函数声明

函数的声明和函数的定义非常类似，唯一的区别是函数声明无须函数体，用一个分号替代即可。

### 分离式编译

## 参数传递

- 引用传递：形参是引用类型时
- 值传递：实参的值被拷贝给形参时

### 传值参数

### 传引用参数

通过使用引用形参，允许函数改变一个或多个实参的值

使用引用避免拷贝  
拷贝大的类类型对象或者容器对象比较低效，甚至有的类类型（包括 IO 类型在内）根本就不支持拷贝操作。当某种类型不支持拷贝操作时，函数只能通过引用形参访问该类型的对象。

使用引用形参返回额外信息  
一个函数只能返回一个值，然而有时函数需要同时返回多个值，引用形参为我们一次返回多个结果提供了有效的途径。

```c++
// 返回s中c第一次出现的位置索引
// 引用形参occurs负责统计c出现的总次数

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.zize();
    occurs = 0;
    for(decltype(ret) i=0;i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
            {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}
auto index = find_char(s, 'c', ctr);
```

### const 形参和实参

实参初始化形参时会忽略掉顶层 const。

尽量使用常量引用  
把函数不会改变的形参定义成（普通的）引用是一种比较常见的错误，这么做带给函数的调用者一种误导，即函数可以修改它的实参的值。此外，使用引用而非常量引用也会极大地限制函数所能接受的实参类型。就像刚刚看到的，我们不能把 const
对象、字面值或者需要类型转换的对象传递给普通的引用形参。

### 数组形参

- 不允许拷贝数组
- 使用数组时（通常）会将其转换成指针

为了保证数组不会越界

- 使用标记指定数组长度
- 使用标准库规范
- 显式传递一个表示数组大小的形参

### main：处理命令行选项

1. 用户通过设置一组选项来确定函数所要执行的操作`prog -d -o ofile data0`
2. 通过两个可选的形参传递给 main 函数`int main(int argc, char *argv[]) {}`

### 含有可变形参的函数

如果所有的实参类型相同，可以传递一个名为 initializer_list 的标准库类型；如果实参的类型不同，我们可以编写一种特殊的函数，也就是所谓的可变参数模板

## 返回类型和 return 语句

return 语句终止当前正在执行的函数并将控制权返回到调用该函数的地方。return 语句有两种形式：

- `return;`
- `return expression;`

### 无返回值函数

没有返回值的 return 语句只能用在返回类型是 void 的函数中。返回 void 的函数不要求非得有 return 语句，因为在这类函数的最后一句后面会隐式地执行 return。

### 有返回值函数

只要函数的返回类型不是 void，则该函数内的每条 return 语句必须返回一个值。return 语句返回值的类型必须与函数的返回类型相同，或者能隐式地转换成函数的返回类型。

```c++
// 因为含有不正确的返回值，这段代码无法通过编译
bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
    {
        return str1 == str2;
    }
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
        {
            return; // 没有返回值
        }
    }
    // 控制流可能尚未返回任何值就结束了函数的执行
}
```

返回一个值的方式和初始化一个变量或形参的方式完全一样：返回的值用于初始化调用点的一个临时量，该临时量就是函数调用的结果。

```c++
// 该函数的返回类型是string，意味着返回值将被拷贝到调用点。因此，该函数将返回word的副本或者一个未命名的临时string对象，该对象的内容是word和ending的和。
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (crt > 1) ? word + ending : word;
}

// 其中形参和返回类型都是const string的引用，不管是调用函数还是返回结果都不会真正拷贝string对象。
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
```

不要返回局部变量对象的引用或指针

```c++
// 严重错误，试图返回局部变量的引用
const string &manIp()
{
    string ret;
    ret = "12345";
    if (!ret.empty())
    {
        return ret; // 错误，返回局部对象的引用
    }
    else {
        return "EMPTY"; // 错误，“EMPTY”是一个局部临时量
    }
}
```

引用返回左值

```c++
char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

int main()
{
    string s("a value");
    cout << s << endl;
    get_val(s,0) = 'A';
    cout << s << endl;
    return 0;
}
```

列表初始化返回值

```c++
vector<string> process()
{
    if (expected.empty()) {
        return {};
    } else {
        return {"abc", expected, actual};
    }
}
```

### 返回数组指针

## 函数重载

如果同一作用域内的几个函数名字相同但形参列表不同，我们称之为重载（overloaded）函数。

不允许两个函数除了返回类型外其他所有的要素都相同。

const_cast 和重载

```c++
// 比较两个string对象的长度，返回较短的那个引用
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

当它的实参不是常量时，得到的结果是一个普通的引用
string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string&> (s1), const_cast<const string&>s2);
    return const_cast<string&>(r);
}
```

调用重载的函数

- 编译器找到一个与实参最佳匹配（best match）的函数，并生成调用该函数的代码。
- 找不到任何一个函数与调用的实参匹配，此时编译器发出无匹配（no match）的错误信息。
- 有多于一个函数可以匹配，但是每一个都不是明显的最佳选择。此时也将发生错误，称为二义性调用（ambiguous call）。

### 重载与作用域

如果我们在内层作用域中声明名字，它将隐藏外层作用域中声明的同名实体。

```c++
string read();
void print(const string &);
void print(double); // 重载print函数
void fooBar(int val)
{
    bool read = false; // 新作用域，隐藏了外层的read
    string s = read(); // 错误：read是一个布尔值，而不是函数

    void print(int); // 新作用域：隐藏了之前的print
    print("Value : "); // 错误，print(const string &)被隐藏了
    print(val); // 正确
    print(3.14); // 正确，调用print(int)，而非print(double)
}
```

## 特殊用途语言特性

### 默认实参

某些函数有这样一种形参，在函数的很多次调用中它们都被赋予一个相同的值，此时，我们把这个反复出现的值称为函数的默认实参（default
argument）。`string screen(sz ht=24, wid=80, char background='');`

只要表达式的类型能转换成形参所需的类型，该表达式就能作为默认实参。

### 内联函数和 constexpr 函数

内联函数可以避免函数调用的开销

将函数指定为内联函数（inline），通常就是将它在每个调用点上“内联地”展开

```c++
cout << shorterString(s1, s2) << endl;
// >>>>>>>
cout<< (s1.size() <= s2.size() ? s1 : s2) << endl;
```

constexpr 函数（constexpr function）是指能用于常量表达式的函数。

函数的返回类型及所有形参的类型都得是字面值类型，而且函数体中必须有且只有一条 return 语句。`constexpr int new_sz() { return 42; }`

### 调试帮助

assert 预处理宏`assert(expr)`: 首先对 expr 求值，如果表达式为假（即 0），assert 输出信息并终止程序的执行。如果表达式为真（即非 0），assert 什么也不做。

NDEBUG 预处理变量：assert 的行为依赖于一个名为 NDEBUG 的预处理变量的状态。如果定义了 NDEBUG，则 assert 什么也不做。默认状态下没有定义 NDEBUG，此时 assert 将执行运行时检查。

- `_ _FILE_ _` 存放文件名的字符串字面值。
- `_ _LINE_ _` 存放当前行号的整型字面值。
- `_ _TIME_ _` 存放文件编译时间的字符串字面值。
- `_ _DATE_ _` 存放文件编译日期的字符串字面值。

## 函数匹配

确定候选函数和可行函数

候选函数：一是与被调用的函数同名，二是其声明在调用点可见。  
可行函数：一是其形参数量与本次调用提供的实参数量相等，二是每个实参的类型与对应的形参类型相同，或者能转换成形参的类型。

寻找最佳匹配（如果有的话）：逐一检查函数调用提供的实参，寻找形参类型与实参类型最匹配的那个可行函数。

### 实参类型转换

1. 精确匹配，包括以下情况：
    - 实参类型和形参类型相同。
    - 实参从数组类型或函数类型转换成对应的指针类型。
    - 向实参添加顶层 const 或者从实参中删除顶层 const。
2. 通过 const 转换实现的匹配。
3. 通过类型提升实现的匹配。
4. 通过算术类型转换或指针转换实现的匹配。
5. 通过类类型转换实现的匹配。

## 函数指针

函数指针指向的是函数而非对象。和其他指针一样，函数指针指向某种特定类型。函数的类型由它的返回类型和形参类型共同决定，与函数名无关。

```c++
bool lengthCompare(const string &, const string &);

// pf指向一个函数，该函数的参数是两个const string的引用，返回值是bool
bool (*pf) (const string &, const string &); // 未初始化

// 使用函数指针
pf = lengthCompare;
pf = &lengthCompare;

bool b1 = pf("hello", "goodbye");
bool b2 = (*pf)("hello", "goodbye");
bool b3 = lengthCompare("hello", "goodbye");
```

编译器通过指针类型决定选用哪个函数，指针类型必须与重载函数中的某一个精确匹配。

虽然不能返回一个函数，但是能返回指向函数类型的指针。

## 习题集

- 传值参数、传引用参数、数组参数和可变参数
- 无返回值、有返回值、返回数组指针
- 同名函数重载及重载函数的匹配

### 形参、局部变量、局部静态变量区别

- 形参是一种自动对象，函数开始时为形参申请内存空间，我们用调用函数时提供的实参初始化形参对应的自动对象。
- 普通变量对应的自动对象也容易理解，我们在定义该变量的语句处创建自动对象，如果定义语句提供了初始值，则用该值初始化；否则，执行默认初始化。当该变量所在的块结束后，变量失效。
- 局部静态变量比较特殊，它的生命周期贯穿函数调用及之后的时间。局部静态变量对应的对象称为局部静态对象，它的生命周期从定义语句处开始，直到程序结束才终止。

### 值传递、引用传递

一是可以直接操作引用形参所引的对象；二是使用引用形参可以避免拷贝大的类类型对象或容器类型对象；三是使用引用形参可以帮助我们从函数中返回多个值。

适合用引用类型的场合：

- 当函数的目的是交换两个参数的内容时应该使用引用类型的形参
- 当参数是 string 对象时，为了避免拷贝很长的字符串，应该使用引用类型

### 普通引用作为参数的局限性

一是容易给使用者一种误导，即程序允许修改变量 s 的内容；二是限制了该函数所能接受的实参类型，我们无法把 const 对象、字面值常量或者需要进行类型转换的对象传递给普通的引用形参。

### 将数组作为函数形参

实际上，因为数组传入函数时实参自动转换成指向数组首元素的指针。

- 声明为指针
- 声明为不限维度的数组
- 声明为维度确定的数组

### 参数是 initializer_list 的函数

```c++
#include <iostream>

using namespace std;

int count(initializer_list<int> il) {
    int count = 0;
    for(auto val : il){
        count += val;
    }
    return count;
}

int main(){
    cout << count({1,2,3,4}) << endl;
    cout << count({10,10,10,10,10}) << endl;
}
```

### 返回左值

```c++
int &get(int *arr, int index){
    return arr[index];
}

int main() {
    int ia[10];
    for(int i = 0; i < 10; ++i){
        get(ia, i) = i;
    }
}
```
