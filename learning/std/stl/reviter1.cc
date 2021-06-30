#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    for (int i = 1; i <= 9; ++i) {
        v.push_back(i);
    }
    copy(v.crbegin(), v.crend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}