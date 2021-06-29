#include <deque>
#include <list>
#include <vector>

using namespace std;

void odd() {
    list<int>  lst = {1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> odd_q, even_q;

    for (auto iter = lst.cbegin(); iter != lst.cend(); ++iter) {
        if (*iter & 1) {
            odd_q.push_back(*iter);
        } else {
            even_q.push_back(*iter);
        }
    }
}

void add() {
    vector<int>           iv       = {1, 1, 2, 1};
    int                   val      = 1;
    vector<int>::iterator itr      = iv.begin();
    int                   org_size = iv.size(), new_ele = 0;

    while (itr != (iv.begin() + org_size / 2 + new_ele)) {
        if (*itr == val) {
            itr = iv.insert(itr, 2 * val);
            new_ele++;
            itr++;
            itr++;
        } else {
            itr++;
        }
    }
}