#include "timepoint.hpp"

#include <chrono>
#include <iostream>

int main() {
    auto tp1 = makeTimePoint(2020, 01, 01, 00, 00);
    std::cout << asString(tp1) << std::endl;

    auto tp2 = makeTimePoint(2021, 06, 16, 14, 00, 00);
    std::cout << asString(tp2) << std::endl;
}