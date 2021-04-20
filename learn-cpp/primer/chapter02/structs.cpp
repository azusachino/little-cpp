#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    // 重载操作符
    friend std::istream &operator>>(std::istream &, Sales_data &);

    friend std::istream &operator<<(std::istream &, Sales_data &);

    friend std::istream &operator<(std::istream &, Sales_data &);

    friend std::istream &operator==(std::istream &, Sales_data &);

public:
    Sales_data() = default;

    Sales_data(const std::string &book) : bookNo(book) {}

    Sales_data(std::istream &is) {
        is >> *this;
    }

public:
    Sales_data &operator+=(const Sales_data &);

    std::string isbn() const {
        return bookNo;
    }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double sellingPrice = 0.0;
    double realSellPrice = 0.0;
    double discount = 0.0;
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

Sales_data operator+(const Sales_data &, const Sales_data &);

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return false;
}