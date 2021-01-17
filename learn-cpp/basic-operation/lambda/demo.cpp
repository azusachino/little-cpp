#include "vector"
#include <iostream>

using namespace std;

int test() {
    // 以传值方式
    [=](int x) -> {
        cout << x << endl;
    };

    [](string arr) -> {
        cout << arr << endl;
        return 0;
    };
    return 0;
};
