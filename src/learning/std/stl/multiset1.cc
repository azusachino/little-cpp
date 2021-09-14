#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    multiset<string> cities{"HF", "BJ", "SH", "GZ", "SZ", "NYC"};
    for (const auto &e: cities) {
        cout << e << " ";
    }
    cout << endl;

    cities.insert({"London", "Munich", "Hanover", "NYC"});

    for (const auto &e: cities) {
        cout << e << " ";
    }
    cout << endl;
}