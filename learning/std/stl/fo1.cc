#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>

#include "print.hpp"

using namespace std;

int main() {
    deque<int> dq = {1, 2, 3, 4, 5, 6, 7, 8, 98, 9};
    PRINT_ELEMENTS(dq, "initialized: ");

    transform(dq.cbegin(), dq.cend(), dq.begin(), negate<int>());
    PRINT_ELEMENTS(dq, "negated: ");

    transform(dq.cbegin(), dq.cend(), dq.cbegin(), dq.begin(),
              multiplies<int>());
    PRINT_ELEMENTS(dq, "multiplied: ");
}