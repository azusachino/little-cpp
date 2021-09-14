#include <forward_list>

#include "print.h"

using namespace std;

int main() {
    forward_list<int> l1 = {1, 2, 3, 4, 5};
    forward_list<int> l2 = {97, 98, 99};

    auto pos1 = l1.before_begin();
    for (auto p1 = l1.begin(); p1 != l1.end(); ++p1, ++pos1) {
        if (*p1 == 3) {
            break;
        }
    }

    auto pos2 = l2.before_begin();
    for (auto p2 = l2.begin(); p2 != l2.end(); ++p2, ++pos2) {
        if (*p2 == 99) {
            break;
        }
    }
    l1.splice_after(pos2, l2, pos1);
    PRINT_ELEMENTS(l1, "l1: ");
    PRINT_ELEMENTS(l2, "l2: ");
}