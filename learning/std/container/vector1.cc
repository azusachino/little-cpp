#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> v;
    v.reserve(5);

    v.push_back("Hello, ");
    v.insert(v.end(), {"how", "are", "you", "?"});

    copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cout << "max_size(): " << v.max_size() << endl;
    cout << "size(): " << v.size() << endl;
    cout << "capacity(): " << v.capacity() << endl;

    swap(v[1], v[3]);
    v.insert(find(v.begin(), v.end(), "?"), "always");

    v.back() = "!";

    copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cout << "size(): " << v.size() << endl;
    cout << "capacity(): " << v.capacity() << endl;

    v.pop_back();
    v.pop_back();
    v.shrink_to_fit();

    cout << "size(): " << v.size() << endl;
    cout << "capacity(): " << v.capacity() << endl;
}