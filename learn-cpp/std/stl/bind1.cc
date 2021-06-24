#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>

#include "print.hpp"

using namespace std;
using namespace std::placeholders;

int main() {
    set<int, greater<int>> s = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int>             dq;

    PRINT_ELEMENTS(s, "initialized: ");

    transform(s.cbegin(), s.cend(), back_inserter(dq),
              bind(multiplies<int>(), _1, 10));
    PRINT_ELEMENTS(dq, "tranformed: ");

    replace_if(dq.begin(), dq.end(), bind(equal_to<int>(), _1, 70), 42);
    PRINT_ELEMENTS(dq, "replaced: ");

    dq.erase(
        remove_if(dq.begin(), dq.end(),
                  bind(logical_and<bool>(), bind(greater_equal<int>(), _1, 50),
                       bind(less_equal<int>(), _1, 80))),
        dq.end());
    PRINT_ELEMENTS(dq, "removed: ");
}