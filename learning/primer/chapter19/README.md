# 特殊工具与技术

## 控制内存分配

### 重载 new 和 delete

new 的三步骤：  
第一步，new 表达式调用一个名为 `operator new`（或者 `operator new[]`）的标准库函数。该函数分配一块足够大的、原始的、未命名的内存空间以便存储特定类型的对象（或者对象的数组）。第二步，编译器运行相应的构造函数以构造这些对象，并为其传入初始值。第三步，对象被分配了空间并构造完成，返回一个指向该对象的指针。

delete 的两步骤：  
第一步，对 sp 所指的对象或者 arr 所指的数组中的元素执行对应的析构函数。第二步，编译器调用名为`operator delete`（或者`operator delete[]`）的标准库函数释放内存空间。

```c++
string *sp = new string("a value");
string *arr = new string[10];

delete sp; // destroy sp, then release space *sp refers
delete [] arr; // destroy elements in array, release related space
```

标准库定义了`opeartor new` 和 `operator delete`的 8 个重载版本，前四个可能抛出 bad_alloc 异常：

```c++
void *operator new(size_t);
void *operator new[] (size_t);
void *operator delete(void*) noexcept;
void *operator delete[] (void*) noexcept;

void *operator new(size_t, nothrow_t&) noexcept;
void *operator new[](size_t, nothrow_t&) noexcept;
void *operator delete(void*,  nothrow_t&) noexcept;
void *operator delete[] (void*,  nothrow_t&) noexcept;
```

## 运行时类型识别(RTTI)

- typeid 运算符，用于返回表达式的类型。
- dynamic_cast 运算符，用于将基类的指针或引用安全地转换成派生类的指针或引用。

```c++
dynamic_cast<type*>(e)
dynamic_cast<type&>(e)
dynamic_cast<type&&>(e)
```

typeid 表达式的形式是 typeid（e），其中 e 可以是任意表达式或类型的名字。typeid 操作的结果是一个常量对象的引用，该对象的类型是标准库类型 type_info 或者 type_info 的公有派生类型。

```c++
Derived *dp = new Derived;
Base *bp = dp;

if (typeid(*bp) == typeid(*dp)) {

}
// typeid应该作用于对象
if (typeid(*bp) == typeid(Derived)) {

}
```

## 枚举类型

C++11 新标准引入了限定作用域的枚举类型（scoped enumeration）。定义限定作用域的枚举类型的一般形式是：首先是关键字 enum class（或者等价地使用 enum struct），随后是枚举类型名字以及用花括号括起来的以逗号分隔的枚举成员（enumerator）列表，最后是一个分号。

```c++
enum class open_modes {input, output, append};
// wrong, context error
open_modes i = input;

enum color {red, yellow, green};
color a = red; // ok

// with specific type
enum intValues: unsigned long long {
    charTyp = 255,
    shortTyp = 65535,
    intTyp = 65535,
    longTyp = 4294967295UL
};
```

在限定作用域的枚举类型中，枚举成员的名字遵循常规的作用域准则，并且在枚举类型的作用域外是不可访问的。

## 类成员指针

```c++
class Screen {
public:
    typedef std::string::size_type pos;
    char get_cursor() const {
        return contents[cursor];
    }
    char get() const;
private:
    std::string contents;
    pos cursor;
    pos height, width;
};

const string Screen::*pdata; // a pointer points Screen::member(string)
pdata = &Screen::contents;

auto pdata = &Screen::contents;
```

## 嵌套类

```c++
class TextQuery {
    public:
    class QueryResult;
};

class TextQuery::QueryResult {
    // class definition
};
```

## unio：节省空间的类

联合（union）是一种特殊的类。一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当我们给 union 的某个成员赋值之后，该 union 的其他成员就变成未定义的状态了。分配给一个 union 对象的存储空间至少要能容纳它的最大的数据成员。和其他类一样，一个 union 定义了一种新类型。

```c++
union Token {
    char cval;
    int ival;
    double dval;
}

Token first_token = {'a'};
Token last_token;
Token *pt = new Token;
```

## 局部类

类可以定义在某个函数的内部，我们称这样的类为局部类（local class）。局部类定义的类型只在定义它的作用域内可见。和嵌套类不同，局部类的成员受到严格限制。

## 固有不可移植的特性

### 位域

类可以将其（非静态）数据成员定义成位域（bit-field），在一个位域中含有一定数量的二进制位。当一个程序需要向其他程序或硬件设备传递二进制数据时，通常会用到位域。

位域在内存中的布局是与机器相关的。

### volatile

程序可能包含一个由系统时钟定时更新的变量。当对象的值可能在程序的控制或检测之外被改变时，应该将该对象声明为 volatile。关键字 volatile 告诉编译器不应对这样的对象进行优化。

### extern "C"
