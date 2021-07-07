# 用于大型程序的工具

## 异常处理

异常处理（exception handling）机制允许程序中独立开发的部分能够在运行时就出现的问题进行通信并做出相应的处理。

### 栈展开

当抛出一个异常后，程序暂停当前函数的执行过程并立即开始寻找与异常匹配的 catch 子句。当 throw 出现在一个 try 语句块（try block）内时，检查与该 try 块关联的 catch 子句。如果找到了匹配的 catch，就使用该 catch 处理异常。如果这一步没找到匹配的 catch 且该 try 语句嵌套在其他 try 块中，则继续检查与外层 try 匹配的 catch 子句。如果还是找不到匹配的 catch，则退出当前的函数，在调用当前函数的外层函数中继续寻找。

### 捕获异常

### 函数 try 语句块与构造函数

```c++
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) try : data(std::make_shared<std::vector<T>>(il)) {
} catch(const std::bad_alloc &e) { handle_out_of_memory(e);}
```

### noexcept 异常说明

```c++
noexcept(recoup(i)); // throw exception return false
```

## 命名空间

首先是关键字 namespace，随后是命名空间的名字。在命名空间名字后面是一系列由花括号括起来的声明和定义。只要能出现在全局作用域中的声明就能置于命名空间内，主要包括：类、变量（及其初始化操作）、函数（及其定义）、模板和其他命名空间

```c++
namespace cp {
    class SaleData {}
    SaleData operator+(const SaleData&, const SaleData&);

    class Query {}
    class QueryBase {}
}
cp::Query q = cp::Query("hello");
```

```c++
namespace std {
    template <> struct hash<SaleData>;
}
template <> std::hash<SaleData> {
    size_t operator() (const SaleData& s) const {
        return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
    }
}
```

inline namespace, unnamed namespace

```c++
namespace blip {
    int i = 16, j = 15, k = 23;
}

int j = 0;
void manip()
{
    using namespace blip;
    ++i; // set blip::i => 17
    ++j; // wrong, ambiguous
    ++::j; // set global j => 1
    ++blip::j; // set blip::j => 16
    int k = 97;
    ++k; // set local k => 98
}
```

## 多重继承与虚继承

多重继承（multiple inheritance）是指从多个直接基类中产生派生类的能力。

如果一个类是从多个基类直接继承而来的，那么有可能这些基类本身又共享了另一个基类。在这种情况下，中间类可以选择使用虚继承，从而声明愿意与层次中虚继承同一基类的其他类共享虚基类。用这种方法，后代派生类中将只有一个共享虚基类的副本。
