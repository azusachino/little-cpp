#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    multimap<string, string> dict;

    dict.insert({{"day", "Tag"},
                 {"strange", "fremd"},
                 {"car", "auto"},
                 {"smart", "elegant"}});
    cout.setf(ios::left, ios::adjustfield);
    cout << ' ' << setw(10) << "english "
         << "german " << endl;
}