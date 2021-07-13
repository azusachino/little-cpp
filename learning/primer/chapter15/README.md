# 面向对象程序设计

## 概述

面向对象程序设计（object-orientedprogramming）的核心思想是数据抽象、继承和动态绑定。

对于某些函数，基类希望它的派生类各自定义适合自身的版本，此时基类就将这些函数声明成虚函数（virtualfunction）。

## 定义基类与派生类

[quote.cc](quote.cc)

- 从派生类向基类的类型转换只对指针或者引用类型有效
- 基类向派生类不存在隐式类型转换
- 派生类向基类的类型转换可能由于访问受限而变得不可行

## 虚函数

对虚函数的调用可能在运行时才被解析

```c++
struct B {
  virtual void f1(int) const;
  virtual void f2();
  void f3();
};

struct D1 : B {
    void f1(int) const override; // CORRECT, pair with f1 in B
    void f2(int) override; // WRONG, no f2(int) in B
    void f3() override; // WRONG, f3 not a virtual function
    void f4() override; // WRONG, no f4 in B
};

// force call function in BASE struct
double undiscounted = baseP->Quote::net_price(42);
```

## 抽象基类

通过在函数体的位置书写`=0`就可以将一个虚函数说明为纯虚函数。

派生类构造函数只初始化它的直接基类。

## 访问控制与继承

protected:

- 和私有成员类似，受保护的成员对于类的用户来说是不可访问的。
- 和公有成员类似，受保护的成员对于派生类的成员和友元来说是可访问的。
- 派生类的成员或友元只能通过派生类对象来访问基类的受保护成员。派生类对于一个基类对象中的受保护成员没有任何访问特权。

```c++
class Base {
protected:
    int prot_mem;
};

class Sneaky : public Base {
    friend void clobber(Sneaky&); // can access Sneaky::prot_mem
    friend void clobber(Base&); // can't access Base::prot_mem
    int j; // default private
};

void clobber(Sneaky &s) {
    s.j = s.prot_mem = 0;
}

// Wrong, can't access Base::protectedElement
void clobber(Base &b) {
    b.prot_mem = 0;
}
```

某个类对其继承而来的成员的访问权限受到两个因素影响：一是在基类中该成员的访问说明符，二是在派生类的派生列表中的访问说明符。

```c++
class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};
struct Pub_Derv : public Base {
    // can access protected element
    int f() {
        return prot_mem;
    }
    // wrong, can't access private element
    char g() {
        return priv_mem;
    }
};

struct Priv_Derv : private Base {
    // private does not affect access
    int f1() const {
        return prot_elem;
    }
}

struct Derived_from_Public : public Pub_Derv {
    int use_base() {
        return prot_mem; // ok
    }
};

struct Derived_from_Private : public Priv_Derv {
    int use_base() {
        return prot_mem; // wrong, private
    }
};
```

友元关系不能传递，也不能继承。

```c++
class Base {
public:
    std::size_t size() const {return n;}
protected:
    std::size_t n;
};

class Derived : private Base {
    // save 
public:
    using Base::size;
protected:
    using Base::n;
};
```

## 构造函数与拷贝控制

```c++
Quote *qp = new Quote();
delete qp; // call ~Quote()
qp = new Bulk_Quote();
delete qp; // call ~Bulk_Quote()
```

```c++
class B {
public:
    B();
    B(const &B) = delete; 
};
class D : public B {
};

D d; // call default
D d2(d); // wrong, copy constructor was deleted
D d3(std::move(d)); // wrong, implicit call copy constructor
```

```c++
class Base {};
class D : public Base {
public:
    D(const &d): Base(d){}
    D(D &&d) : Base(std::move(d)) {}
};
```

## 容器与继承

## 习题集

```sh
(a)%通常定义为非成员。
(b)%=通常定义为类成员，因为它会改变对象的状态。
(c)++通常定义为类成员，因为它会改变对象的状态。
(d)->必须定义为类成员，否则编译会报错。
(e)<<通常定义为非成员。
(f)&&通常定义为非成员。
(g)==通常定义为非成员。
(h)()必须定义为类成员，否则编译会报错。
```
