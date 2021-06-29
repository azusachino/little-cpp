#include <iostream>
#include <string>

using namespace std;

// 定义在类内部的函数是隐式的inline函数

struct Sales_data {
    // 构造函数
    Sales_data() = default;  // 默认的（合成）构造函数
    Sales_data(const string &s) : bookNo(s) {}

    Sales_data(const string &s, unsigned n, double p)
        : bookNo(s), uints_sold(n), revenue(p * n) {}

    Sales_data(std::istream &);

    // 关于Sales_data对象的操作
    string isbn() const { return bookNo; }

    Sales_data &combine(const Sales_data &);

    double avg_price() const;

    string   bookNo;
    unsigned uints_sold = 0;
    double   revenue    = 0.0;
};

// 非成员接口函数
Sales_data add(const Sales_data &, const Sales_data &);

std::ostream &print(std::ostream &, const Sales_data &);

std::istream &read(std::istream &, Sales_data &);

// 在类的外部定义构造函数
Sales_data::Sales_data(std::istream &is) { read(is, *this); }
