#include <algorithm>
#include <iostream>
#include <list>

#include "print.hpp"

using namespace std;

class AddValue {
private:
    int value;

public:
    AddValue(int v) : value(v) {}
    void operator()(int& e) const { e += value; }
};

int main() {
    list<int> l;
    for (int i = 1; i <= 9; ++i) {
        l.push_back(i);
    }
    PRINT_ELEMENTS(l, "initialized:   ");

    for_each(l.begin(), l.end(), AddValue(10));

    PRINT_ELEMENTS(l, "after adding 10: ");

    for_each(l.begin(), l.end(), AddValue(*l.begin()));
    PRINT_ELEMENTS(l, "after adding first value: ");
}