#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main() {
    list<int> l;
    for (int i = 1; i <= 6; ++i) {
        l.push_front(i);
        l.push_back(i);
    }
    cout << "pre: ";
    copy(l.cbegin(), l.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    remove(l.begin(), l.end(), 3);

    cout << "post: ";
    copy(l.cbegin(), l.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}