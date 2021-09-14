# 用于学习 CPP 的仓库

## CPP 基础

### 头文件和源文件

- 头文件(.h)：写类的声明（包括类里面的成员和方法的声明）、函数原型、#define 常数等，但一般来说不写出具体的实现。
- 源文件(.cpp):主要写实现头文件中已经声明的那些函数的具体代码。需要注意的是，开头必须#include 一下实现的头文件，以及要用到的头文件。那么当你需要用到自己写的头文件中的类时，只需要#include 进来就行了。

### 定义

C++ 是一种静态类型的、编译式的、通用的、大小写敏感的、不规则的编程语言，支持过程化编程、面向对象编程和泛型编程。

### 特点

- 封装
- 抽象
- 继承
- 多态

### 标准库

- 核心语言，提供了所有构件块，包括变量、数据类型和常量，等等。
- C++ 标准库，提供了大量的函数，用于操作文件、字符串等。
- 标准模板库（STL），提供了大量的方法，用于操作数据结构等。

最简单的编译方式 -> g++ helloworld.cpp -o helloworld(可执行文件) (在 windows 就是 exe 文件)

### 数据类型

| 类型     | 关键字  |
| -------- | ------- |
| 布尔型   | bool    |
| 字符型   | char    |
| 整型     | int     |
| 浮点型   | float   |
| 双浮点型 | double  |
| 无类型   | void    |
| 宽字符型 | wchar_t |

- 使用 typedef 为一个已有的类型取一个新的名字 -> typedef int feet;
- 枚举类型 enum color{red, blue=5, green};

变量声明向编译器保证变量以给定的类型和名称存在

- 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
- 右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值 => 右值是不能对其进行赋值的表达式，右值只可以出现在赋值号的右边。

### 作用域

- 在函数或一个代码块内部声明的变量，称为局部变量。
- 在函数参数的定义中声明的变量，称为形式参数。
- 在所有函数外部声明的变量，称为全局变量。

| 数据类型 | 初始化默认值 |
| -------- | ------------ |
| int      | 0            |
| char     | '\0'         |
| float    | 0            |
| double   | 0            |
| pointer  | NULL         |

### 常量

常量是固定值，在程序执行期间不会改变。这些固定的值，又叫做字面量。可分为整型数字、浮点数字、字符、字符串和布尔值。

- 使用 #define 预处理器。
- 使用 const 关键字。(定义成 const 后的常量，程序对其中只能读不能修改。)

区别: 类型和安全检查不同, 编译器处理不同, 存储方式不同, 定义域不同, 定义后能否取消, 是否可以做函数参数

### 修饰符

signed、unsigned、long 和 short 可应用于整型，signed 和 unsigned 可应用于字符型，long 可应用于双精度型。

| 限定符   | 含义                                                                                                                                                                         |
| -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| const    | const 类型的对象在程序执行期间不能被修改改变。                                                                                                                               |
| volatile | 修饰符 volatile 告诉编译器不需要优化 volatile 声明的变量，让程序可以直接从内存中读取变量。对于一般的变量编译器会对变量进行优化，将内存中的变量值放在寄存器中以加快读写效率。 |
| restrict | 由 restrict 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符 restrict。                                                                           |

### 关键字

存储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。下面列出 C++ 程序中可用的存储类： auto, register, static, extern, mutable,
thread_local (C++11)

- `auto` 关键字用于两种情况：声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。 `auto f = 3.14;`
- `register` 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。`register int miles;`
- `static` 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。 `static int count = 10;`
- extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。 `extern void write_extern();`
- `mutable` 说明符仅适用于类的对象
- `thread_local` 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。
- `sizeof` 运算符返回变量的大小。例如，sizeof(a) 将返回 4，其中 a 是整数。
- 指针运算符 `&`返回变量的地址。例如 `&a`; 将给出变量的实际地址。
- 指针运算符 `*`指向一个变量。例如，`*var`将指向变量 var。

### 定义函数

- **返回类型**：一个函数可以返回一个值。return_type 是函数返回的值的数据类型。有些函数执行所需的操作而不返回值，在这种情况下，return_type 是关键字 void。
- **函数名称**：这是函数的实际名称。函数名和参数列表一起构成了函数签名。
- **参数**：参数就像是占位符。当函数被调用时，您向参数传递一个值，这个值被称为实际参数。参数列表包括函数参数的类型、顺序、数量。参数是可选的，也就是说，函数可能不包含参数。
- **函数主体**：函数主体包含一组定义函数执行任务的语句。

### Lambda

`lambda [capture](parameters)->return-type{body}`

[=,&](int x, int y){ return x < y ; } => = 表示以传值方式, & 表示以引用方式

- [capture]：捕捉列表。捕捉列表总是出现在 lambda 表达式的开始处。事实上，[] 是 lambda 引出符。编译器根据该引出符判断接下来的代码是否是 lambda 函数。捕捉列表能够捕捉上下文中的变量供 lambda
  函数使用。
- (parameters)：参数列表。与普通函数的参数列表一致。如果不需要参数传递，则可以连同括号 () 一起省略。 -` mutable：mutable 修饰符。默认情况下，lambda 函数总是一个 const 函数，mutable
  可以取消其常量性。在使用该修饰符时，参数列表不可省略（即使参数为空）。
- ->return_type：返回类型。用追踪返回类型形式声明函数的返回类型。出于方便，不需要返回值的时候也可以连同符号 -> 一起省略。此外，在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导。
- {statement}：函数体。内容与普通函数一样，不过除了可以使用参数之外，还可以使用所有捕获的变量。

### 字符串

**字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。**

char msg[] = "Hello" === char msg[] = {'H', 'e', 'l', 'l', 'o', '\0'};

### 指针

每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址。

- `&` 符号的意思是取地址，也就是返回一个对象在内存中的地址。
- `*` 符号的意思是取得一个指针所指向的对象。 也就是如果一个指针保存着一个内存地址，那么它就返回在那个地址的对象。

### 引用相关

- 不存在空引用。引用必须连接到一块合法的内存。
- 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
- 引用必须在创建时被初始化。指针可以在任何时间被初始化。

struct 定义一种结构 typedef struct xx{} xx => 之后就可以直接使用 xx 而不需要声明 struct xx 了

### 日期和时间

C++ 标准库没有提供所谓的日期类型。C++ 继承了 C 语言用于日期和时间操作的结构和函数。为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 `<ctime>` 头文件。

有四个与时间相关的类型：clock_t、time_t、size_t 和 tm。类型 clock_t、size_t 和 time_t 能够把系统时间和日期表示为某种整数。

```c++
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
};
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
   cout << "本地日期和时间：" << dt << endl;
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;
}
```

### 基本输入输出`<iostream>`

- cout: `cout << "Value of str is : " << str << endl;`
- cin: `cout << "请输入您的名称： "; cin >> name; cout << "您的名称是： " << name << endl;`
- cerr: `cerr << "Error message : " << str << endl;`
- clog: `clog << "Error message : " << str << endl;`

### 数据结构

C/C++ 数组允许定义可存储相同类型数据项的变量，但是结构是 C++ 中另一种用户自定义的可用的数据类型，它允许您存储不同类型的数据项。

```c++
struct type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3;
.
.
} object_names;

```

---

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

typedef struct Student {
    char name[50];
    int age;
    char from[50];
} Student;

int main ()
{
  // 变量定义
  int var = 20;
  int a, b;
  int c;
  float f;
  int *ip;

  ip = &var; // 在指针变量中存储 var 的地址
  cout << "Value of var variable: "; // 20
  cout << var << endl;

  // 输出在指针变量中存储的地址
  cout << "Address stored in ip variable: "; // hex(0xbfc601ac)
  cout << ip << endl;

  // 访问指针中地址的值
  cout << "Value of *ip variable: "; // 20
  cout << *ip << endl;
  // 实际初始化
  a = 10;
  b = 20;
  c = a + b;

  cout << c << endl;

  f = 70.0/3.0;
  cout << f << endl;
  printSomething();
  return 0;
  // 基于当前系统的当前日期/时间
   time_t now = time(0);

   // 把 now 转换为字符串形式
   char* dt = ctime(&now);

   cout << "本地日期和时间：" << dt << endl;

   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;

    Student student{
            .name="aaa",
            .age=20,
            .from = "hefei"
    };
    Student *studentPtr = &student;
    cout << studentPtr->age;
    cout << student.age;
}

void printSomething(){}
```

## CMAKE_LIST.txt

```c++
#CMake最低版本号要求
cmake_minimum_required(VERSION 3.12)
#项目信息
project(little_cpp)
#使用C++ 11标准
set(CMAKE_CXX_STANDARD 11)
#指定生成目标
add_executable(learn_cpp main.cpp)
1.cmake_minimum_required ：指定运行此程序所需要的CMake的最低版本
2.project ：参数为：'chapter5_01'，表示该项目名称是：chapter5_01
3.set：参数为：CMAKE_CXX_STANDARD 11，表示：设置C++标准为 C++ 11
4.add_executable：参数为：chapter5_01和main.cpp，表示：将名为main.cpp的文件编译为名为chapter5_01的可执行文件
```

## 命名规范

### 1. 通用命名规则

总述

函数命名, 变量命名, 文件命名要有描述性; 少用缩写.

说明

尽可能使用描述性的命名, 别心疼空间, 毕竟相比之下让代码易于新读者理解更重要. 不要用只有项目开发者能理解的缩写, 也不要通过砍掉几个字母来缩写单词.

规范命名

```c++
int price_count_reader;    // 无缩写
int num_errors;            // "num" 是一个常见的写法
int num_dns_connections;   // 人人都知道 "DNS" 是什么
```

不规范命名

```c++
int n;                     // 毫无意义.
int nerr;                  // 含糊不清的缩写.
int n_comp_conns;          // 含糊不清的缩写.
int wgc_connections;       // 只有贵团队知道是什么意思.
int pc_reader;             // "pc" 有太多可能的解释了.
int cstmr_id;              // 删减了若干字母.
```

注意, 一些特定的广为人知的缩写是允许的, 例如用 i 表示迭代变量和用 T 表示模板参数.

模板参数的命名应当遵循对应的分类: 类型模板参数应当遵循 类型命名 的规则, 而非类型模板应当遵循 变量命名 的规则.

### 2. 文件命名

总述

文件名要全部小写, 可以包含下划线 () 或连字符 (-), 依照项目的约定. 如果没有约定, 那么 “” 更好.

说明

可接受的文件命名示例:

```bash
my_useful_class.cc
my-useful-class.cc
myusefulclass.cc
myusefulclass_test.cc // _unittest 和 _regtest 已弃用.
```

引自 C++ Primer Plus 第五版中文版 P8

C++实现源代码的扩展名 UNIX ： C、cc、cxx、c GNU C++ ：C、cc、cxx、cpp、c++ Borland C++ ： Cpp Microsoft Visual C++ ： cpp、cxx、cc Android
系统源码中以 cc 为后缀 参考了 C++ Primer Plus 第五版中文版 P8

不要使用已经存在于 /usr/include 下的文件名 (即编译器搜索系统头文件的路径), 如 db.h.

通常应尽量让文件名更加明确. http_server_logs.h 就比 logs.h 要好. 定义类时文件名一般成对出现, 如 foo_bar.h 和 foo_bar.cc, 对应于类 FooBar.

内联函数必须放在 .h 文件中. 如果内联函数比较短, 就直接放在 .h 中.

### 3. 类型命名

总述

类型名称的每个单词首字母均大写, 不包含下划线: MyExcitingClass, MyExcitingEnum.

说明

所有类型命名 —— 类, 结构体, 类型定义 (typedef), 枚举, 类型模板参数 —— 均使用相同约定, 即以大写字母开始, 每个单词首字母均大写, 不包含下划线. 例如:

```c++
// 类和结构体
class UrlTable {
...
class UrlTableTester {
...
struct UrlTableProperties {
...

// 类型定义
typedef hash_map<UrlTableProperties *, string> PropertiesMap;

// using 别名
using PropertiesMap = hash_map<UrlTableProperties *, string>;

// 枚举
enum UrlTableErrors { ...
```

### 4. 变量命名

总述

变量 (包括函数参数) 和数据成员名一律小写, 单词之间用下划线连接. 类的成员变量以下划线结尾, 但结构体的就不用, 如: a*local_variable, a_struct_data_member,
a_class_data_member*.

说明

普通变量命名 举例:

```c++
string table_name;  // 好 - 用下划线.
string tablename;   // 好 - 全小写.

string tableName;  // 差 - 混合大小写
```

类数据成员  
不管是静态的还是非静态的, 类数据成员都可以和普通变量一样, 但要接下划线。

```c++
class TableInfo {
  ...
 private:
  string table_name_;  // 好 - 后加下划线.
  string tablename_;   // 好.
  static Pool<TableInfo>* pool_;  // 好.
};
```

结构体变量 不管是静态的还是非静态的, 结构体数据成员都可以和普通变量一样, 不用像类那样接下划线:

```c++
struct UrlTableProperties {
  string name;
  int num_entries;
  static Pool<UrlTableProperties>* pool;
};
```

### 5. 常量命名

总述

声明为 constexpr 或 const 的变量, 或在程序运行期间其值始终保持不变的, 命名时以 “k” 开头, 大小写混合. 例如:

```c++
const int kDaysInAWeek = 7;
```

说明

所有具有静态存储类型的变量 (例如静态变量或全局变量, 参见 存储类型) 都应当以此方式命名. 对于其他存储类型的变量, 如自动变量等, 这条规则是可选的. 如果不采用这条规则, 就按照一般的变量命名规则.

### 6. 函数命名

总述

常规函数使用大小写混合, 取值和设值函数则要求与变量名匹配:

```c++
MyExcitingFunction()
MyExcitingMethod()
my_exciting_member_variable()
set_my_exciting_member_variable()
```

说明

一般来说, 函数名的每个单词首字母大写 (即 “驼峰变量名” 或 “帕斯卡变量名”), 没有下划线. 对于首字母缩写的单词, 更倾向于将它们视作一个单词进行首字母大写 (例如, 写作 StartRpc() 而非 StartRPC()).

```c++
AddTableEntry()
DeleteUrl()
OpenFileOrDie()
```

(同样的命名规则同时适用于类作用域与命名空间作用域的常量, 因为它们是作为 API 的一部分暴露对外的, 因此应当让它们看起来像是一个函数, 因为在这时, 它们实际上是一个对象而非函数的这一事实对外不过是一个无关紧要的实现细节.)

取值和设值函数的命名与变量一致. 一般来说它们的名称与实际的成员变量对应, 但并不强制要求. 例如 int count() 与 void set_count(int count).

### 7. 命名空间命名

总述

命名空间以小写字母命名. 最高级命名空间的名字取决于项目名称. 要注意避免嵌套命名空间的名字之间和常见的顶级命名空间的名字之间发生冲突.

顶级命名空间的名称应当是项目名或者是该命名空间中的代码所属的团队的名字. 命名空间中的代码, 应当存放于和命名空间的名字匹配的文件夹或其子文件夹中.

注意 不使用缩写作为名称 的规则同样适用于命名空间. 命名空间中的代码极少需要涉及命名空间的名称, 因此没有必要在命名空间中使用缩写.

要避免嵌套的命名空间与常见的顶级命名空间发生名称冲突. 由于名称查找规则的存在, 命名空间之间的冲突完全有可能导致编译失败. 尤其是, 不要创建嵌套的 std 命名空间. 建议使用更独特的项目标识符 (websearch::index
，websearch::index_util) 而非常见的极易发生冲突的名称 (比如 websearch::util).

对于 internal 命名空间, 要当心加入到同一 internal 命名空间的代码之间发生冲突 (由于内部维护人员通常来自同一团队, 因此常有可能导致冲突). 在这种情况下, 请使用文件名以使得内部名称独一无二 (例如对于
frobber.h, 使用 websearch::index::frobber_internal).

### 8. 枚举命名

总述

枚举的命名应当和 常量 或 宏 一致: kEnumName 或是 ENUM_NAME.

说明

单独的枚举值应该优先采用 常量 的命名方式. 但 宏 方式的命名也可以接受. 枚举名 UrlTableErrors (以及 AlternateUrlTableErrors) 是类型, 所以要用大小写混合的方式.

```c++
enum UrlTableErrors {
    kOK = 0,
    kErrorOutOfMemory,
    kErrorMalformedInput,
};
enum AlternateUrlTableErrors {
    OK = 0,
    OUT_OF_MEMORY = 1,
    MALFORMED_INPUT = 2,
};
```

2009 年 1 月之前, 我们一直建议采用 宏 的方式命名枚举值. 由于枚举值和宏之间的命名冲突, 直接导致了很多问题. 由此, 这里改为优先选择常量风格的命名方式. 新代码应该尽可能优先使用常量风格. 但是老代码没必要切换到常量风格,
除非宏风格确实会产生编译期问题.

### 9. 宏命名

总述

你并不打算 使用宏, 对吧? 如果你一定要用, 像这样命名: MY_MACRO_THAT_SCARES_SMALL_CHILDREN.

说明

参考 预处理宏; 通常 不应该 使用宏. 如果不得不用, 其命名像枚举命名一样全部大写, 使用下划线:

```c++
#define ROUND(x) ...
#define PI_ROUNDED 3.0
```

### 10. 命名规则的特例

如果你命名的实体与已有 C/C++ 实体相似, 可参考现有命名策略.

- bigopen(): 函数名, 参照 open() 的形式
- uint: typedef
- bigpos: struct 或 class, 参照 pos 的形式
- sparse_hash_map: STL 型实体; 参照 STL 命名约定
- LONGLONG_MAX: 常量, 如同 INT_MAX

## differences between gcc & g++

- gcc can compile `*.c` or `*.cpp` files as C and C++ respectively
- g++ can also compile `*.c` and `*.cpp` files, but take both as C++ file
- If we want to use g++ to link the object files, it automatically links in the STD C++ libraries. The gcc does not do
  that
- gcc compiles C files which has fewer predefined macros
- gcc compiles C++ files with more number of predefined macros, and also g++ compiles with more predefined macros.
