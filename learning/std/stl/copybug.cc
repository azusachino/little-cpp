#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int main() {
    list<int>   l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> l2;
    copy(l1.cbegin(), l1.cend(), l2.begin());
}