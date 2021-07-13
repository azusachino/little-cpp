#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
    set<int, greater<int>> s;
    s.insert({4, 3, 5, 1, 2, 6});
    s.insert(5);

    for (auto e : s) {
        cout << e << " ";
    }
    cout << endl;

    auto status = s.insert(4);
    if (status.second) {
        cout << "4 inserted as element "
             << distance(s.begin(), status.first) + 1 << endl;
    } else {
        cout << "4 already exists" << endl;
    }

    set<int> s2(s.begin(), s.end());
    copy(s2.cbegin(), s2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    s2.erase(s2.begin(), s2.find(3));

    int num = s2.erase(5);
    cout << num << "element(s) removed" << endl;

    copy(s2.cbegin(), s2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}