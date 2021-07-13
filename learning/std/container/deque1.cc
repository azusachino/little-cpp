#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main() {
    deque<string> d;

    d.assign(3, string("string"));
    d.push_back("last string");
    d.push_front("first string");

    copy(d.cbegin(), d.cend(), ostream_iterator<string>(cout, "\n"));
    cout << endl;

    d.pop_front();
    d.pop_back();

    for (unsigned int i = 1; i < d.size(); ++i) {
        d[i] = "another " + d[i];
    }

    d.resize(4, "resized string");
    copy(d.cbegin(), d.cend(), ostream_iterator<string>(cout, "\n"));
}