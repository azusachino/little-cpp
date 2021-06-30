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
    l.erase(remove(l.begin(), l.end(), 3), l.end());

    l.remove(4);
}