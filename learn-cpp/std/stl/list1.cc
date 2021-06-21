#include <iostream>
#include <list>

using namespace std;

int main() {
    list<char> ch;

    for (char c = 'a'; c <= 'z'; ++c) {
        ch.push_back(c);
    }

    for (auto e : ch) {
        cout << e << ' ';
    }
    cout << endl;
}