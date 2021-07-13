#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> v;

    copy(istream_iterator<string>(cin), istream_iterator<string>(),
         back_inserter(v));

    sort(v.begin(), v.end());

    unique_copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, "\n"));
}