#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>

using namespace std;

int main() {
    list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> v;
    copy(l.cbegin(), l.cend(), back_inserter(v));

    deque<int> dq;
    copy(l.cbegin(), l.cend(), front_inserter(dq));

    set<int> s;
    copy(l.cbegin(), l.cend(), inserter(s, s.begin()));
}