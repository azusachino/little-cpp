#include <algorithm>
#include <deque>
#include <list>
#include <vector>

using namespace std;

int main() {
    list<int>   l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> l2;
    l2.resize(l1.size());

    copy(l1.cbegin(), l1.cend(), l2.begin());

    deque<int> l3(l1.size());
    copy(l1.cbegin(), l1.cend(), l3.begin());
}