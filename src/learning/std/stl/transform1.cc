#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

#include "print.hpp"

int square(int value) { return value * value; }

int main() {
    std::set<int> s;
    std::vector<int> v;

    for (int i = 1; i <= 9; ++i) {
        s.insert(i);
    }

    PRINT_ELEMENTS(s, "initialized: ");

    std::transform(s.cbegin(), s.cend(), std::back_inserter(v), square);

    PRINT_ELEMENTS(v, "squared:   ");
}