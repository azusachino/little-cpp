#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// void print(int e) { cout << e << " "; }
class PrintInt {
public:
    void operator()(int e) const { cout << e << " "; }
};

int main() {
    vector<int> v;

    for (int i = 1; i <= 9; ++i) {
        v.push_back(i);
    }
    for_each(v.cbegin(), v.cend(), PrintInt());
    cout << endl;
}