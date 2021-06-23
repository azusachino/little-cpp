#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> dq = {1, 3, 5, 7, 9, 13, 14, 15, 19};
    int        x  = 5;
    int        y  = 13;
    auto       pos =
        find_if(dq.cbegin(), dq.cend(), [=](int i) { return i > x && i < y; });
    cout << "first ele > 5 and < 12 : " << *pos << endl;
}