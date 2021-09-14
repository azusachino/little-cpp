#include <algorithm>
#include <array>
#include <functional>
#include <numeric>

#include "print.h"

using namespace std;

int main() {
    array<int, 10> a = {11, 22, 33, 44};
    PRINT_ELEMENTS(a);

    a.back() = 99999;
    a[a.size() - 2] = 42;
    PRINT_ELEMENTS(a);

    cout << "sum: " << accumulate(a.begin(), a.end(), 0) << endl;

    transform(a.begin(), a.end(), a.end(), negate<int>());
    PRINT_ELEMENTS(a);
}