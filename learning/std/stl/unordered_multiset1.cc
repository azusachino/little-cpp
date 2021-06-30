#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
        unordered_multiset<string> cities{"HF", "BJ", "SH", "GZ", "SZ", "NYC"};
    for (const auto& e : cities) {
        cout << e << " ";
    }
    cout << endl;

    cities.insert({"London", "Munich", "Hanover", "NYC"});

    for (const auto& e : cities) {
        cout << e << " ";
    }
    cout << endl;
}