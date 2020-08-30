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
右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。

在函数或一个代码块内部声明的变量，称为局部变量。
在函数参数的定义中声明的变量，称为形式参数。
在所有函数外部声明的变量，称为全局变量。

常量是固定值，在程序执行期间不会改变。这些固定的值，又叫做字面量。可分为整型数字、浮点数字、字符、字符串和布尔值。
使用 #define 预处理器。
使用 const 关键字。(定义成 const 后的常量，程序对其中只能读不能修改。)
区别: 类型和安全检查不同, 编译器处理不同, 存储方式不同, 定义域不同, 定义后能否取消, 是否可以做函数参数

修饰符 signed、unsigned、long 和 short 可应用于整型，signed 和 unsigned 可应用于字符型，long 可应用于双精度型。

存储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。下面列出 C++ 程序中可用的存储类：
auto, register, static, extern, mutable, thread_local (C++11)
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
