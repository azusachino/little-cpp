#include <iostream>
#include <string>
#include <unordered_set>

#include "hashval.h"
#include "print.h"

using namespace std;

class Customer {
private:
    string fname;
    string lname;
    long no;

public:
    Customer(const string &fn, const string &ln, long n)
            : fname(fn), lname(ln), no(n) {}

    friend ostream &operator<<(ostream &strm, const Customer &c) {
        return strm << "[" << c.fname << "," << c.lname << "," << c.no << "]";
    }

    friend class CustomerHash;

    friend class CustomerEqual;
};

class CustomerHash {
public:
    std::size_t operator()(const Customer &c) const {
        return hash_val(c.fname, c.lname, c.no);
    }
};

class CustomerEqual {
public:
    bool operator()(const Customer &c1, Customer &c2) const {
        return c1.no == c2.no;
    }
};

int main() {
    unordered_set<Customer, CustomerHash, CustomerEqual> cset;
    cset.insert(Customer("nico", "kiwi", 42));
    PRINT_ELEMENTS(cset);
}