#include <iostream>
#include <typeinfo>

int main() {
    int  i = 5, j = 10;
    int *p = &i;

    std::cout << p << " " << *p << std::endl;  // 地址1 5
    p = &j;
    std::cout << p << " " << *p << std::endl;  // 地址2 10
    *p = 20;
    std::cout << p << " " << *p << std::endl;  // 地址2 20
    j = 30;
    std::cout << p << " " << *p << std::endl;  // 地址2 30
    return 0;
}

void auto_test() {
    int       i = 0, &r = i;
    auto      a  = r;
    const int ci = i, &cr = ci;
    auto      b = ci;
    auto      c = cr;
    auto      d = &i;
    auto      e = &ci;
    auto &    g = ci;
    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g
              << std::endl;

    a = 1;
    b = 1;
    c = 1;
    // d = 1; 指针
    // e = 1; 指针
    // g = 1;  常量引用

    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g
              << std::endl;
}

void type_info() {
    const int   i  = 42;          // 整型常量
    auto        j  = i;           // 整数
    const auto &k  = i;           // 整型常量
    auto *      p  = &i;          // 指向整型常量的指针
    const auto  j2 = i, &k2 = i;  // j2整数，k2整数

    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(j).name() << std::endl;
    std::cout << typeid(k).name() << std::endl;
    std::cout << typeid(p).name() << std::endl;
    std::cout << typeid(j2).name() << std::endl;
    std::cout << typeid(k2).name() << std::endl;
}

void decl_info() {
    int           a  = 3;  // 整数
    auto          c1 = a;  // 整数
    decltype(a)   c2 = a;  // int
    decltype((a)) c3 = a;  // int refer

    const int   d  = 5;  // const int
    auto        f1 = d;  // int (ignore const)
    decltype(d) f2 = d;  // const int
}