# 一般概念

## 命名空间 std

使用 c++标准库中的任何标识符，三种选择：

- 直接指定标识符 `std::cout << std::hex << 3.4 << std::endl;`
- 使用`using declaration` => `using std::cout;`
- 使用`use directive` => ·using namespace std;`

## 头文件

旧式的 c 标准头文件任然有效。

```c++
#include <stdlib.h> // old c way
#include <iostream> // c++

#include <string> // c++ class string
#include <cstring> // char* functions from C
```

## Error & Exception

标准异常类分为三组：

- 语言本身支持的异常
- C++标准库产生的异常
- 程序作用域之外产生的异常

### 针对语言支持而设计的异常类

- 运行期间，当一个加诸 reference 身上的“动态类型转换”失败时，dynamic_cast 会抛出 bad_cast 异常，此异常定义于＜ typeinfo ＞。
- 运行期类型辨识（RTTI）过程中，如果交给 typeid 操作符的实参为 0 或为空指针，typeid 操作符会抛出 bad_typeid 异常，此异常定义于＜ typeinfo ＞。
- 定义于 ＜ exception ＞内的 bad_exception 异常被用来处理非预期的异常。

### 针对逻辑错误而设计的异常类

- invalid_argument 表示无效实参，例如将 bitset（array ofbits）以 char 而非'0'或'1'进行初始化。
- length_error 指出某个行为“可能超越最大容许大小”，例如对某个字符串附加太多字符。
- out_of_range 指出实参值“不在预期范围内”，例如在类似 array 的集合（array-like collection）或字符串（string）中采用一个错误索引。
- domain_error 指出领域范畴（domain）内的错误。
- 自 C++11 起，future_error 用来指出当使用非同步系统调用时发生的逻辑差错。

### 针对运行错误而设计的异常类

- range_error 指出内部计算时发生区间错误（range error）。自 C++11 起，C++标准库有可能在“wide string 和 byte string 之间转换”时发生这个异常。
- overflow_error 指出算术运算发生上溢（overflow）。C++标准库中如果一个 bitset 被转换为一个整数值，就会抛出这个异常。
- underflow_error 指出算术运算发生下溢（underflow）。
- 自 C++11 起，system_error 用来指出因底层操作系统而发生的差错。C++标准库有可能在并发环境中抛出这个异常。
- 只要全局操作符 new 失败，定义于＜ new ＞的 bad_alloc 就会被抛出，除非用的是 new 的 nothrow 版本。由于这个异常可能于任何时间在任何较复杂程序中发生，所以可说是最重要的一个异常。自 C++11 起，派生自
  bad_alloc 的 bad_array_new_length 会被 new 抛出——如果传给 new 的大小小于 0 或超过编译器定义的极限（也就是说，那将是个逻辑错误而不是个运行期错误）。
- 当“根据一个 shared pointer 创建出一个 weak pointer”的操作失败，定义于＜ memory ＞中的 bad_weak_ptr 会被抛出。
- 当一个 function 外覆物（wrapper object）被调用但其实没有目标（target）时，定义于＜ functional ＞中的 bad_function_call 会被抛出。

### 异常类的头文件

```c++
#include <exception> // for classes exception and bad_exception
#include <stdexcept> // for most logic and runtime error classes
#include <system_error> // for system errors (since c++11)
#include <new> // for out-of-memory exceptions
#include <ios> // for I/O exceptions
#include <future> // for errors with async() and futures (since c++11)
#include <typeinfo> // for bad_cast and bad_typeid
```

### 异常类的成员

**what()**:

```c++
namespace std {
    class exception {
        public:
            virtual const char* what() const noexcept;
            ...
    };
}
```

- Error code 是一种轻型对象（light-weight object），用来封装差错码值（error code value），后者可能由编译器实现指定（所谓
  implementation-specific），不过也有某些差错码是标准化的。
- Error condition 是一种提供“差错描述之可移植性抽象层”（portable abstrac-tions of error descriptions）的对象。

```c++
if (ec == std::errc::invalid_argument) {
    // check for specific error condition
}
if (ec == std::future_errc::no_state) {
    // check for specific error code
}
```

### 以 Class exception_ptr 传递异常

```c++
#include <exception>

std::exception_ptr eptr;

void foo() {
    try {
        throw exception;
    } catch(e) {
        eptr = std::current_exception();
    }
}
void bar() {
    if (eptr != nullptr) {
        std::rethrow_exception(eptr);
    }
}
```

## Callable Object

- 函数
- 指向成员函数的指针
- 函数对象
- lambda

## 并发与多线程

面对被多线程共享的某个标准库类型的某个对象，改动它会造成‘导致不明确行为’的风险。除非该类型的对象被明确指定为‘sharable without data races’或使用者为它提供了一个 locking 机制。

## Allocator

C++标准库在许多地方采用特殊对象处理内存的分配和归还，这样的对象称为 allocator （分配器）。Allocator 表现出一种特殊内存模型（memory model），被当成一种用来把“内存需求”转换为“内存低级调用”的抽象层。
