#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    multimap<int, string> m;
    m = {{5, "tagged"},
         {2, "a"},
         {1, "this"},
         {4, "of"},
         {6, "strings"},
         {1, "is"},
         {3, "multimap"}};
    for (auto e: m) {
        cout << e.second << " ";
    }
    cout << endl;
}