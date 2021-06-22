#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v      = {2, 5, 4, 6, 12, 2};
    auto        minPos = min_element(v.cbegin(), v.cend());

    auto maxPos = max_element(v.cbegin(), v.cend());

    sort(v.begin(), v.end());

    auto p = find(v.begin(), v.end(), 4);

    reverse(p, v.end());

    for (auto e : v) {
        cout << e << endl;
    }
}