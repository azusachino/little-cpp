#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

void elim_dups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elim_dups(words);

    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b) { return a.size() > b.size(); });

    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a) { return a.size() >= sz; });

    auto count = words.end() - wc;

    for_each(wc, words.end(),
             [](const string &s) { cout << s << " "; });
    cout << endl;
}

void bind_() {
    // std::placeholders <functional>
    auto bb = bind(biggies, _1, 5);
}