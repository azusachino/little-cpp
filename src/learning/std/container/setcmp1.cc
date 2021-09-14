#include <iostream>
#include <set>

#include "print.h"

using namespace std;

class RuntimeCmp {
public:
    enum cmp_mode {
        normal, reverse
    };

private:
    cmp_mode mode;

public:
    RuntimeCmp(cmp_mode m = normal) : mode(m) {}

    template<typename T>
    bool operator()(const T &t1, const T &t2) const {
        return mode == normal ? t1 < t2 : t2 < t1;
    }

    bool operator==(const RuntimeCmp &rc) const { return mode == rc.mode; }
};

typedef set<int, RuntimeCmp> IntSet;

int main() {
    IntSet is = {4, 7, 5, 1, 6, 2, 6};
    PRINT_ELEMENTS(is, "is: ");

    RuntimeCmp reverse_order(RuntimeCmp::reverse);
    IntSet is2(reverse_order);
    is2 = {4, 7, 5, 1, 6, 2, 6};
    PRINT_ELEMENTS(is2, "is2: ");

    is = is2;
    is.insert(3);
    PRINT_ELEMENTS(is, "is: ");

    if (is.value_comp() == is2.value_comp()) {
        cout << "same sorting criterion" << endl;
    } else {
        cout << "different sorting criterion" << endl;
    }
}