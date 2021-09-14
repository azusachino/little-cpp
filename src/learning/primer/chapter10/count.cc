#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

void count_(vector<int> &vec, int val) {
    int c = 0;
    for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
        if (*itr == val) {
            c++;
        }
    }
    cout << c << endl;

    cout << count(vec.cbegin(), vec.cend(), val) << endl;
    // cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
}

void ok() {
    list<int> lst;
    vector<int> vec;

    for (int i = 0; i < 10; i++) {
        lst.push_back(i);
    }
    // 利用back_inserter
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    // copy需要两个容器元素数量一致
}

void elim_dups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}