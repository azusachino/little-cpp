#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    for (int i = 20; i <= 40; ++i) {
        l.push_back(i);
    }

    auto pos3 = find(l.begin(), l.end(), 3);
    reverse(pos3, l.end());
    list<int>::iterator pos25, pos35;
    pos25 = find(l.begin(), l.end(), 25);
    pos35 = find(l.begin(), l.end(), 35);
}