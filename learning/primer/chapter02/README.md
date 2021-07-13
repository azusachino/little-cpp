# 变量和基本类型

## 基本内置类型

- 算术类型(arithmetic type)：整型（integral type, 包括字符和布尔型）和浮点型
- 空类型(void)

### 如何选择类型

- 当明确知晓数值不可能为负时，选用无符号类型
- 使用 int 执行整数运算。在实际应用中，short 常常显得太小而 long 一般和 int 有一样的尺寸。如果数值超过了 int 的范围，可以选用 long long。
- 在算术表达式中不要使用 char 或 bool，只有在存放字符或布尔值时才使用它们。
- 执行浮点数运算时选用 double，因为 float 通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。

### 字面值常量

- 20 十进制
- 024 八进制
- 0x13 十六进制

整型字面值具体的数据类型由它的值和符号决定。默认情况下，十进制字面值是带符号数，八进制和十六进制字面值既可能是带符号的也可能是无符号的。十进制字面值的类型是 int、long 和 long long 中尺寸最小的那个（例如，三者当中最小是
int），当然前提是这种类型要能容纳下当前的值。八进制和十六进制字面值的类型是能容纳其数值的 int、unsigned int、long、unsigned long、long long 和 unsigned long long
中的尺寸最小者。如果一个字面值连与之关联的最大的数据类型都放不下，将产生错误。类型 short 没有对应的字面值。

> 切勿混用带符号类型和无符号类型

## 变量

变量提供一个具名的、可供程序操作的存储空间。C++中的每个变量都有其数据类型，数据类型决定着变量所占内存空间的大小和布局方式、该空间能存储的值的范围，以及变量能参与的运算。

### 变量定义

变量定义的基本形式是：首先是类型说明符（type specifier），随后紧跟由一个或多个变量名组成的列表，其中变量名以逗号分隔，最后以分号结束。`std:string book("0-201-78345-X")`

> 初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，而以一个新值来替代。

声明（declaration）使得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。而定义（definition）负责创建与名字关联的实体。

### 四种初始化

```cpp
int a = 0;
int b = {0};
int c{0};
int d(0);
```

## 复合类型

### 引用

引用（reference）为对象起了另外一个名字，引用类型引用（refers to）另外一种类型。

```c++
int iVal = 1024;
int &refVal = ival; // refVal指向ival
int &refVal;
```

### 指针

指针（pointer）是“指向（point to）”另外一种类型的复合类型。

- 指针本身就是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象。
- 指针无须在定义时赋初值。和其他内置类型一样，在块作用域内定义的指针如果没有被初始化，也将拥有一个不确定的值。

```c++
// 指针存放某个对象的地址，要想获取该地址，需要使用取地址符（操作符&）
int iVal = 42;
int *p = &iVal; // p存放变量iVal的地址，或者说p是指向变量iVal的指针
```

#### 指针值

指针的值（地址）应属下列 4 种状态之一：

1. 指向一个对象
2. 指向紧邻对象所占空间的下一个位置
3. 空指针，意味着指针没有指向任何对象
4. 无效指针，也就是上述情况以外的其他值

#### 某些符号有多重含义

像&和＊这样的符号，既能用作表达式里的运算符，也能作为声明的一部分出现，符号的上下文决定了符号的意义：

```c++
int i = 42;
int &r = i; // ref
int *p; // ptr
p = &r; // 取地址符
*p = i; // 解引用符
int &r2 = *p; // &是声明的一部分，*是解引用符
```

空指针（nullptr）不指向任何对象，在试图使用一个指针之前代码可以首先检查它是否为空

```c++
int *p1 = nullptr; // 等价于 int *p1 = 0;
int *p2 = 0; // 直接将p2初始化为字面常量0
// 需要 #include <cstlib>
int *p3 = NULL;
```

#### void\* 指针

`void*`是一种特殊的指针类型，可用于存放任意对象的地址。

#### 指向指针的引用

引用本身不是一个对象，因此不能定义指向引用的指针。但指针是对象，所以存在对指针的引用：

```c++
int i = 42;
int *p; // p是一个int型指针
int *&r = p; // r是一个对指针p的引用
r = &i; // r引用了一个指针，因此给r赋值&i就是令p指向i
*r = 0; // 解引用r得到i，也就是p指向的对象，将i的值改为0
```

## const 限定符

关键字 const 定义常量，const 对象一旦创建后其值就不能再改变，因此 const 对象必须初始化。

```c++
int i = 42;
const ci = i; // 可行，i的值被拷贝给了ci
int j = ci; // 可行，ci的值被拷贝给了j
```

### 默认情况下，const 对象仅在文件内有效

编译器将在编译过程种把用到该变量的地方都替换成对应的值。（默认情况下，const 对象被设定为仅在文件内有效） 如果程序包含多个文件，则每个用了 const 对象的文件都必须得能访问到它的初始值才行。  
如果想在多文件中使用同一个常量，不管是声明还是定义都添加 extern 关键字。

### const 的引用

```c++
const int ci = 1024;
const int &r1 = ci; // 正确，引用及其对应的对象都是常量

r1 = 42; // 错误，r1是对常量的引用
int &r2 = ci; // 错误，试图让一个非常量引用指向一个常量对象

int i = 42;
const int &r1 = i; // 允许将const int&绑定到一个普通int对象上
const int &r2 = 42; // 正确
const int &r2 = r1 * 2; // 正确
int &r4 = r1 * 2; // 错误，r4是一个普通的非常量引用
```

### 指针和 const

指向常量的指针不能用于改变其所指对象的值。

```c++
const double pi = 3.14;
double *ptr = &pi;
const double *cptr = &pi;
*cptr = 42; // 错误，不能给*cptr赋值
```

指针本身是一个常量并不意味着不能通过指针修改其所指对象的值，能否这样做全依赖于所指对象的类型。

```c++
int errNum = 0;
int *const curErr = &errNum; // curErr将一直指向errNum
const double pi = 3.1415;
const double *const pip = &pi; // pip是一个指向常量对象的常量指针
```

### 顶层 const

名词顶层 const（top-level const）表示指针本身是个常量，而用名词底层 const（low-level const）表示指针所指的对象是一个常量。

```c++
int i = 0;
int *const p1 = &i; // 顶层const
const int ci = 42; // 顶层const
const int *p2 = &ci; // 底层const，可以改变p2的值

const int *const p3 = p2; // 靠右的const是顶层const，靠左的是底层const
const int &r = ci; // 用于申明引用的const都是底层const
i = ci; // 正确：拷贝ci的值，ci是一个顶层const
p2 = p3; // 正确：p2和p3指向的对象类型相同，p3的顶层const部分不影响

int *p = p3; // 错误：o3包含底层const的定义，而p没有
p2 = &i; // 正确：int*能转换成const int*
int &r = ci; // 错误：普通的int&不能绑定到int常量上
const int &r2 = i; // 正确：const int&可以绑定到一个普通的int上
```

### constexpr 和常量表达式

常量表达式（const expression）是指值不会改变并且在编译过程就能得到计算结果的表达式。

```c++
// 一个对象（表达式）是不是常量表达式由它的数据类型和初始类型共同决定
const int max_files = 20; // true
const int limit = max_files + 1; // true
int staff_size = 27; // false
const int sz = get_size(); // false
```

C++11 新标准规定，允许将变量声明为 constexpr 类型以便由编译器来验证变量的值是否是一个常量表达式。声明为 constexpr 的变量一定是一个常量，而且必须用常量表达式初始化：

```c++
constexpr int mf = 20; // true
constexpr int limit = mf + 1; // true
constexpr int sz = size(); // 只有当size是一个constexpr函数是才是一条正确的声明语句
```

算术类型、引用和指针都属于字面值类型。一个 constexpr 指针的初始值必须是 nullptr 或者 0，或者是存储与某个固定地址的对象。

```c++
const int *p = nullptr; // p是一个指向整型常量的指针
constexpr int *q = nullptr; // q是一个指向整型的常量指针

constexpr int *np = nullptr; // np是一个指向整型的常量指针，其值为空
int j = 0;
constexpr int i = 45; // i的类型是整型常量
constexpr const int *p = &i; // p是常量指针，指向整型常量i
constexpr int *pi = &j; // pi是常量指针，指向整数j
```

## 处理类型

### 类型别名

类型别名（type alias）是一个名字，它是某种类型的同义词。使用类型别名有很多好处，它让复杂的类型名字变得简单明了、易于理解和使用，还有助于程序员清楚地知道使用该类型的真实目的。

```c++
typedef double wages; // wages是double的别名
typedef wages base, *p; // base是double的同义词，p是double*的同义词

using SI = Sales_item; // SI是Sales_item的别名

typedef char *pstring;
const pstring cstr = 0; // cstr是指向char的常量指针
const pstring *ps; // ps是一个指针，他的对象是指向char的常量指针
```

### auto 类型说明符

C++11 新标准引入了 auto 类型说明符，用它就能让编译器替我们去分析表达式所属的类型。

```c++
auto item = val1+val2;// item初始化为val1和val2相加的结果

auto i = 0, *p = &i; // 正确：i是整数，p是整型指针
auto sz = 0, pi = 3.14; // 错误：sz和pi的类型不一样

// 使用引用其实是使用引用的对象，特别是当引用被用作初始值时，真正参与初始化的其实是引用对象的值。
int j = 0, &r = j;
auto a = r; // a是一个整数

// auto一般会忽略掉顶层const，保留底层const
const int ci = j, &cr = ci;
auto b = ci; // 整数
auto c = cr; // 整数
auto d = &j; // 整数指针
auto e = &ci; // 指向整数常量的指针

// 如果希望推断出的auto类型是一个顶层const
const auto f = ci;

// 将引用的类型设为auto
auto &g = ci; // g是一个整型常量引用，绑定到ci
auto &h = 42; // 错误：不能为非常量引用绑定字面值
const auto &j = 32; // 正确：可以为常量引用绑定字面量

// 如果在一条语句中定义多个变量，&和*只从属于某个声明符，而非基本数据类型的一部分，初始值必须是同一种类型
auto k = ci, &l = i; // k是整数，i是整数引用
auto &m = ci, *p = &ci; // m是对整型常量的引用，p是指向整型常量的指针
auto &n = i, *p2 = &ci; // 错误：i的类型是int而&ci的类型是const int
```

### decltype 类型指示符

C++11 新标准引入了第二种类型说明符 decltype，它的作用是选择并返回操作数的数据类型。

```c++
// 编译器并不实际调用函数f，而是使用当调用发生时f的返回值类型作为sum的类型。
decltype(f()) sum = x; // sum的类型就是函数f的返回类型

// 如果decltype使用的表达式十一i个变量，则decltype返回该变量的类型
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x的类型是const int
decltype(cj) y = x; // y的类型是const int&, y绑定到变量x
decltype(cj) z; // 错误：z是一个引用，必须初始化

// decltype的结果可以是引用类型
int i = 42, *p = &i, &r = i;
decltype(r+0) b; // 正确：加法的结果是int，b是一个（未初始化）int
decltype(*p) c; // 错误：c是int&，必须初始化
```

## 自定义数据结构

以关键字 struct 开始，紧跟着类名和类体（其中类体部分可以为空）。类体由花括号包围形成了一个新的作用域。类内部定义的名字必须唯一，但是可以与类外部定义的名字重复。

```c++

struct Sales_item {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0D;
};
// 类体右侧的表示结束的花括号后必须写一个分号，这是因为类体后面可以紧跟变量名以示对该类型对象的定义，所以分号必不可少
struct Other_item {} accum, trans, *otherPtr;
```

### 预处理器概述

- `#include`指令把一个名字设定为预处理变量
- `#ifdef`当前仅当变量已定义时为真
- `#ifndef`当且仅当变量未定义时为真

一旦检查结果为真，则执行后续操作知道遇到`#endif`指令为止。

```c++
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
    std:string bookNo;
}
#endif
```

## 习题集相关

### C++典型数类型

- 基本内置类型
- 复合类型
- 自定义数据结构

其中，char、int、long、float、double、bool 是最常见的基本内置类型；引用和指针是两种最重要的复合类型；struct 关键字和 class 关键字则常用于声明用户自定义的数据结构。

变量的声明、定义和作用域，顶层 const 和底层 const。

### 顶层 const 和底层 const 对于拷贝操作

顶层 const 不受影响，这是因为拷贝操作并不会改变被拷贝对象的值。底层 const 的限制则不容忽视，拷入和拷出的对象必须具有相同的底层 const 资格，或者两个对象的数据类型必须能够转换。一般来说，非常量可以转换成常量，反之则不行。

### auto 说明符与复合类型、常量混合使用时的各种情形

首先，使用引用其实是使用引用的对象，所以当引用被用作初始值时，真正参与初始化的其实是引用对象的值，编译器以引用对象的类型作为 auto 的推断类型。其次，auto 一般会忽略掉顶层 const，同时保留底层 const。

### 说明由 decltype 指定类型和由 auto 指定类型有何区别

第一，auto 类型说明符用编译器计算变量的初始值来推断其类型，而 decltype 虽然也让编译器分析表达式并得到它的类型，但是不实际计算表达式的值。

第二，编译器推断出来的 auto 类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则。例如，auto 一般会忽略掉顶层 const，而把底层 const 保留下来。与之相反，decltype
会保留变量的顶层 const。

第三，与 auto 不同，decltype 的结果类型与表达式形式密切相关，如果变量名加上了一对括号，则得到的类型与不加括号时会有不同。如果 decltype
使用的是一个不加括号的变量，则得到的结果就是该变量的类型；如果给变量加上了一层或多层括号，则编译器将推断得到引用类型。

### 初始化的几种情况

```c++
string global_str;
int global_int;
int main() {
    int local_int;
    string local_str;
}
```

对于 string 类型的变量来说，因为 string 类型本身接受无参数的初始化方式，所以不论变量定义在函数内还是函数外都被默认初始化为空串。

对于内置类型 int 来说，变量 global_int 定义在所有函数体之外，根据 C++的规定，global_int 默认初始化为 0；而变量 local_int 定义在 main
函数的内部，将不被初始化，如果程序试图拷贝或输出未初始化的变量，将遇到一个未定义的奇异值。
