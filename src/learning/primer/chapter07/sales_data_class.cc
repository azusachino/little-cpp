#include <iostream>
#include <string>

using namespace std;

class SalesData {
    // 友元声明
    friend SalesData add(const SalesData &, const SalesData &);

    friend istream &read(istream &, SalesData &);

    friend ostream &print(ostream &, const SalesData &);

public:
    SalesData() = default;

    SalesData(const string &s, unsigned n, double p)
            : bookNo(s), units_solds(n), revenue(p * n) {}

    SalesData(const string &s) : bookNo(s) {}

    SalesData(istream &);

    string isbn() const { return bookNo; }

    SalesData &combine(const SalesData &);

private:
    string bookNo;
    unsigned units_solds = 0;
    double revenue = 0.0;
};

// 非成员组成部分的声明
SalesData add(const SalesData &, const SalesData &);

istream &read(istream &, SalesData &);

ostream &print(ostream &, const SalesData &);