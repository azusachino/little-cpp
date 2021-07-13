#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
    set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    copy(s.cbegin(), s.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int num = s.erase(3);
    cout << "number of removed elements: " << num << endl;

    copy(s.cbegin(), s.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}