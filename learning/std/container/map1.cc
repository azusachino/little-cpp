#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, double> m{{"tim", 9.9}, {"struppi", 11.66}};
    for_each(m.begin(), m.end(), [](pair<const string, double>& elem) {
        elem.second *= elem.second;
    });
    for_each(m.begin(), m.end(),
             [](const map<string, double>::value_type& elem) {
                 cout << elem.first << ": " << elem.second << endl;
             });
}