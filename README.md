# 用于学习CPP的仓库

## CPP基础

```shell script
C++ 是一种静态类型的、编译式的、通用的、大小写敏感的、不规则的编程语言，支持过程化编程、面向对象编程和泛型编程。
`封装, 抽象, 继承, 多态`

核心语言，提供了所有构件块，包括变量、数据类型和常量，等等。
C++ 标准库，提供了大量的函数，用于操作文件、字符串等。
标准模板库（STL），提供了大量的方法，用于操作数据结构等。
最简单的编译方式 -> g++ helloworld.cpp -o helloworld(可执行文件)

类型	关键字
布尔型	bool
字符型	char
整型	int
浮点型	float
双浮点型	double
无类型	void
宽字符型	wchar_t

使用 typedef 为一个已有的类型取一个新的名字 -> typedef int feet;
枚举类型 enum color{red, blue, green};

变量声明向编译器保证变量以给定的类型和名称存在

左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值 => 右值是不能对其进行赋值的表达式，右值只可以出现在赋值号的右边。

在函数或一个代码块内部声明的变量，称为局部变量。
在函数参数的定义中声明的变量，称为形式参数。
在所有函数外部声明的变量，称为全局变量。

常量是固定值，在程序执行期间不会改变。这些固定的值，又叫做字面量。可分为整型数字、浮点数字、字符、字符串和布尔值。
使用 #define 预处理器。
使用 const 关键字。(定义成 const 后的常量，程序对其中只能读不能修改。)
区别: 类型和安全检查不同, 编译器处理不同, 存储方式不同, 定义域不同, 定义后能否取消, 是否可以做函数参数

修饰符 signed、unsigned、long 和 short 可应用于整型，signed 和 unsigned 可应用于字符型，long 可应用于双精度型。

---

存储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。下面列出 C++ 程序中可用的存储类：
auto, register, static, extern, mutable, thread_local (C++11)
auto 关键字用于两种情况：声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。 auto f = 3.14;
register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。 register int miles;
static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。 static int count = 10;
extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。 extern void write_extern();
mutable 说明符仅适用于类的对象
thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。

sizeof 运算符返回变量的大小。例如，sizeof(a) 将返回 4，其中 a 是整数。
指针运算符 & 返回变量的地址。例如 &a; 将给出变量的实际地址。
指针运算符 * 指向一个变量。例如，*var; 将指向变量 var。

lambda [capture](parameters)->return-type{body}
[=,&](int x, int y){ return x < y ; } => = 表示以传值方式, & 表示以引用方式
 [capture]：捕捉列表。捕捉列表总是出现在 lambda 表达式的开始处。事实上，[] 是 lambda 引出符。编译器根据该引出符判断接下来的代码是否是 lambda 函数。捕捉列表能够捕捉上下文中的变量供 lambda 函数使用。
 (parameters)：参数列表。与普通函数的参数列表一致。如果不需要参数传递，则可以连同括号 () 一起省略。
 mutable：mutable 修饰符。默认情况下，lambda 函数总是一个 const 函数，mutable 可以取消其常量性。在使用该修饰符时，参数列表不可省略（即使参数为空）。
 ->return_type：返回类型。用追踪返回类型形式声明函数的返回类型。出于方便，不需要返回值的时候也可以连同符号 -> 一起省略。此外，在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导。
 {statement}：函数体。内容与普通函数一样，不过除了可以使用参数之外，还可以使用所有捕获的变量。

字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。
char msg[] = "Hello" === char msg[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

```c++
#include <iostream>
using namespace std;

// 常量定义
#define LENGTH 10;  
const int WIDTH 5;

// 变量声明
extern int a, b;
extern int c;
extern float f;
void printSomething();
int main ()
{
  // 变量定义
  int a, b;
  int c;
  float f;
 
  // 实际初始化
  a = 10;
  b = 20;
  c = a + b;
 
  cout << c << endl;
 
  f = 70.0/3.0;
  cout << f << endl;
  printSomething();
  return 0;
}

void printSomething(){}
```
