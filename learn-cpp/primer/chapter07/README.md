# C++ Primer Chapter07

## struct 和 class 的区别

- 使用 class 时，类中的成员默认都是 private 属性的；而使用 struct 时，结构体中的成员默认都是 public 属性的。
- class 继承默认是 private 继承，而 struct 继承默认是 public 继承。
- class 可以使用模板，而 struct 不能。

## 定义抽象数据类型

在类的外部定义成员函数：像其他函数一样，当我们在类的外部定义成员函数时，成员函数的定义必须与它的声明匹配。也就是说，返回类型、参数列表和函数名都得与类内部的声明保持一致。如果成员被声明成常量成员函数，那么它的定义也必须在参数列表后明确指定 const 属性。同时，类外部定义的成员的名字必须包含它所属的类名。

定义一个返回 this 对象的函数

```c++
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    uints_sold += rhs.uints_sold;
    revenue += rhs.revenue;
    return *this;
}
```

### 定义类相关的非成员函数

```c++
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.uints_sold >> price;
    item.revenue = price * item.uints_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.uints_sold <<" " << item.revenue << " " << item.avg_price() << endl;
    return os;
}
```

### 构造函数

每个类都分别定义了它的对象被初始化的方式，类通过一个或几个特殊的成员函数来控制其对象的初始化过程，这些函数叫做构造函数（constructor）。

类通过一个特殊的构造函数来控制默认初始化过程，这个函数叫做默认构造函数（default constructor）。默认构造函数无须任何实参。

### 拷贝、赋值和析构

## 访问控制与封装

- 定义在 public 说明符之后的成员在整个程序内可被访问，public 成员定义类的接口。
- 定义在 private 说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，private 部分封装了（即隐藏了）类的实现细节。

```c++
class Sales_data{
public:
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s){}

private:
    double avg_price() const;
    std:string bookNo;
    unsigned uints_sold = 0;
    double revenue = 0.0;
}
```

类可以在它的第一个访问说明符之前定义成员，对这种成员的访问权限依赖于类定义的方式。如果我们使用 struct 关键字，则定义在第一个访问说明符之前的成员是 public 的；相反，如果我们使用 class 关键字，则这些成员是 private 的。

### 友元

类可以允许其他类或者函数访问它的非公有成员，方法是令其他类或者函数成为它的友元（friend）。

```c++
class Sales_data{

// 为Sales_data的非成员函数做友元声明
friend Sales_data add(const Sales_data&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s){}

private:
    double avg_price() const;
    std:string bookNo;
    unsigned uints_sold = 0;
    double revenue = 0.0;
}
```

友元声明只能出现在类定义的内部，但是在类内出现的具体位置不限。友元不是类的成员也不受它所在区域访问控制级别的约束。

## 类的其他特性

### 类成员

除了定义数据和函数成员之外，类还可以自定义某种类型在类中的别名。由类定义的类型名字和其他成员一样存在访问限制，可以是 public 或者 private 中的一种。

可变数据成员 `mutable`：一个可变数据成员（mutable data member）永远不会是 const，即使它是 const 对象的成员。

```c++
class Screen{
public:
    void some() const;
private:
    mutable size_t access_ctr; // 即使在一个const对象内也能被修改
};
void Screen::some() const{
    ++access_ctr; // 保存一个计数器，用于记录成员函数被调用的次数
}
```

### 返回*this的成员函数

从const成员函数返回`*this`：一个const成员函数如果以引用的形式返回`*this`，那么它的返回类型将会是常量引用。

### 类类型

我们也能仅仅声明类而暂时不定义它：`class Screen;`

不完全类型只能在非常有限的情景下使用：可以定义指向这种类型的指针或引用，也可以声明（但是不能定义）以不完全类型作为参数或者返回类型的函数。

### 友元再探

## 类的作用域

每个类都会定义它自己的作用域。在类的作用域之外，普通的数据和函数成员只能由对象、引用或者指针使用成员访问运算符来访问。对于类类型成员则使用作用域运算符访问。

### 名字查找与类的作用域

- 首先，在名字所在的块中寻找其声明语句，只考虑在名字的使用之前出现的声明。
- 如果没找到，继续查找外层作用域。
- 如果最终没有找到匹配的声明，则程序报错。

```c++
typedef double Money;
string bal;
class Account {
public:
    Money balance() {
        return bal;
    }
private:
    Money bal;
}
```

成员定义中的普通块作用域的名字查找

- 首先，在成员函数内查找该名字的声明。和前面一样，只有在函数使用之前出现的声明才被考虑。
- 如果在成员函数内没有找到，则在类内继续查找，这时类的所有成员都可以被考虑。
- 如果类内也没找到该名字的声明，在成员函数定义之前的作用域内继续查找。

## 习题集

### 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public说明符之后？什么样的成员应该定义在private说明符之后？

在类的定义中，可以包含0个或者多个访问说明符，并且对于某个访问说明符能出现多少次以及能出现在哪里都没有严格规定。每个访问说明符指定接下来的成员的访问级别，有效范围直到出现下一个访问说明符或者到达类的结尾为止。

一般来说，作为接口的一部分，构造函数和一部分成员函数应该定义在public说明符之后，而数据成员和作为实现部分的函数则应该跟在private说明符之后。

### class和struct有什么区别

类可以在它的第一个访问说明符之前定义成员，对这种成员的访问权限依赖于类定义的方式。如果使用struct关键字，则定义在第一个访问说明符之前的成员是public的；相反，如果使用class关键字，则这些成员是private的。

### 友元在什么时候有用？

当非成员函数确实需要访问类的私有成员时，我们可以把它声明成该类的友元。此时，友元可以“工作在类的内部”，像类的成员一样访问类的所有数据和函数。但是一旦使用不慎（比如随意设定友元），就有可能破坏类的封装性。
