#include <iostream>
#include <string>

// PRINT_ELEMENTS()
template <typename T>
inline void PRINT_ELEMENTS(const T& v, const std::string& optstr = "") {
    std::cout << optstr;
    for (const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}