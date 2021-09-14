#include <iostream>
#include <set>

using namespace std;

int main() {
    typedef set<int> IntSet;

    IntSet is;

    is.insert(3);
    is.insert(3);

    IntSet::const_iterator p;

    for (p = is.begin(); p != is.end(); ++p) {
        cout << *p << endl;
    }
}