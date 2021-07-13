#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, double> m{{"tim", 9.9}, {"struppi", 11.77}};

    for (pair<const string, double>& e : m) {
        e.second *= e.second;
    }

    for (const auto& e : m) {
        cout << e.first << " : " << e.second << endl;
    }
}