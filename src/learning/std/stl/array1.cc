#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
    array<string, 5> a = {"hello", "world"};

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
}