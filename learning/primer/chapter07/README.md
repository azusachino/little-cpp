# 类

## struct 和 class 的区别

- 使用 class 时，类中的成员默认都是 private 属性的；而使用 struct 时，结构体中的成员默认都是 public 属性的。
- class 继承默认是 private 继承，而 struct 继承默认是 public 继承。
- class 可以使用模板，而 struct 不能。

## 定义抽象数据类型

在类的外部定义成员函数：像其他函数一样，当我们在类的外部定义成员函数时，成员函数的定义必须与它的声明匹配。也就是说，返回类型、参数列表和函数名都得与类内部的声明保持一致。如果成员被声明成常量成员函数，那么它的定义也必须在参数列表后明确指定
const 属性。同时，类外部定义的成员的名字必须包含它所属的类名。

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

类可以在它的第一个访问说明符之前定义成员，对这种成员的访问权限依赖于类定义的方式。如果我们使用 struct 关键字，则定义在第一个访问说明符之前的成员是 public 的；相反，如果我们使用 class 关键字，则这些成员是
private 的。

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

### 返回\*this 的成员函数

从 const 成员函数返回`*this`：一个 const 成员函数如果以引用的形式返回`*this`，那么它的返回类型将会是常量引用。

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

## 构造函数再探

### 构造函数初始化值列表

原来的版本初始化了它的数据成员，而这个版本是对数据成员执行了赋值操作。

```c++
Sales_data::Sales_data(const string &s, unsigned cnt, double price)
{
    // 皆为赋值操作
    bookNo = s;
    units_sold = cnt;
    revenue = cnt * price;
}
```

如果成员是 const 或者是引用的话，必须将其初始化。当成员属于某种类类型且该类没有定义默认的构造函数时，也必须将该成员初始化。

最好令构造函数初始值的顺序与成员声明的顺序保持一致。而且如果可能的话，尽量避免使用某些成员初始化其他成员。

```c++
class X {
    int i;
    int j;
public:
    // i在j之前被初始化
    X(int val): j(val), i(j) {}
}
```

### 委托构造函数

构造函数的重载，复用同一个参数最多的构造函数。

```c++
Class A
{
public:
    A(string &s, unsigned cnt, double price): bookNo(s),units_sold(cnt), revenue(cnt * price){}
    A(): A("", 0, 0){}
    A(string &s): A(s, 0, 0){}
}
```

### 默认构造函数的作用

当对象被默认初始化或值初始化时自动执行默认构造函数。

默认初始化：

- 当我们在块作用域内不使用任何初始值定义一个非静态变量或者数组时。
- 当一个类本身含有类类型的成员且使用合成的默认构造函数时。
- 当类类型的成员没有在构造函数初始值列表中显式地初始化时。

值初始化：

- 在数组初始化的过程中如果我们提供的初始值数量少于数组的大小时。
- 当我们不使用初始值定义一个局部静态变量时。
- 当我们通过书写形如 T（ ）的表达式显式地请求值初始化时，其中 T 是类型名。

### 隐式的类类型转换

如果构造函数只接受一个实参，则它实际上定义了转换为此类类型的隐式转换机制，有时我们把这种构造函数称作转换构造函数。

```c++
string null_book = "9-999-999-9";
// 构造一个临时的sales_data对象
// 该对象的units_sold和revenue等于0，bookNo等于null_book
item.combine(null_book);
```

通过`explicit`阻止隐式的类类型转换

- 只允许一步类类型转换
- 类类型转换不是总有效
- 抑制构造函数定义的隐式转换
- explicit 构造函数只能用于直接初始化
- 为转换显示地使用构造函数(static_cast)
- 标准库中含有显式构造函数的类

### 聚合类

聚合类（aggregate class）使得用户可以直接访问其成员，并且具有特殊的初始化语法形式。

- 所有成员都是 public 的。
- 没有定义任何构造函数。
- 没有类内初始值
- 没有基类，也没有 virtual 函数

```c++
struct Data{
    int ival;
    string s;
}
// 可以使用花括号初始化聚合类
Data val1 = {0, "anna"};
// 初始值顺序和声明的顺序必须一致
```

显式初始化类的对象成员三个明显的缺点：

- 要求类的所有成员都是 public 的。
- 将正确初始化每个对象的每个成员的重任交给了类的用户（而非类的作者）。因为用户很容易忘掉某个初始值，或者提供一个不恰当的初始值，所以这样的初始化过程冗长乏味且容易出错。
- 添加或删除一个成员之后，所有的初始化语句都需要更新。

### 字面值常量类

- 数据成员都必须是字面值类型。
- 类必须至少含有一个 constexpr 构造函数。
- 如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式；或者如果成员属于某种类类型，则初始值必须使用成员自己的 constexpr 构造函数。
- 类必须使用析构函数的默认定义，该成员负责销毁类的对象

constexpr 构造函数必须初始化所有数据成员，初始值或者使用 constexpr 构造函数，或者是一条常量表达式。

constexpr 构造函数用于生成 constexpr 对象以及 constexpr 函数的参数或返回类型

```c++
class Debug{
    public:
    constexpr Debug(bool b = true): hw(b),io(b),other(b){}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
    constexpr bool any() {
        return hw || io || other;
    }
    void set_io(bool b){
        io = b;
    }
    void set_hw(bool b){
        hw = b;
    }
    void set_other(bool b) {
        other = b;
    }
    private:
    bool hw;
    bool io;
    bool other;
}
```

## 类的静态成员

我们通过在成员的声明之前加上关键字 static 使得其与类关联在一起。

```c++
class Account {
public:
    void calculate() {
        amount += amount * interestRate;
    }
    static double rate() {
        return interestRate;
    }
    static void rate(double);
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
}

// 使用作用域运算符直接访问静态成员
double r = Account::rate();
```

## 习题集

### 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在 public 说明符之后？什么样的成员应该定义在 private 说明符之后？

在类的定义中，可以包含 0 个或者多个访问说明符，并且对于某个访问说明符能出现多少次以及能出现在哪里都没有严格规定。每个访问说明符指定接下来的成员的访问级别，有效范围直到出现下一个访问说明符或者到达类的结尾为止。

一般来说，作为接口的一部分，构造函数和一部分成员函数应该定义在 public 说明符之后，而数据成员和作为实现部分的函数则应该跟在 private 说明符之后。

### class 和 struct 有什么区别

类可以在它的第一个访问说明符之前定义成员，对这种成员的访问权限依赖于类定义的方式。如果使用 struct 关键字，则定义在第一个访问说明符之前的成员是 public 的；相反，如果使用 class 关键字，则这些成员是 private 的。

### 友元在什么时候有用？

当非成员函数确实需要访问类的私有成员时，我们可以把它声明成该类的友元。此时，友元可以“工作在类的内部”，像类的成员一样访问类的所有数据和函数。但是一旦使用不慎（比如随意设定友元），就有可能破坏类的封装性。
