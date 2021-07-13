#include <forward_list>
#include <iostream>

using namespace std;

int main() {
    forward_list<long> fl = {2, 3, 5, 7, 11, 13, 17};

    fl.resize(9);
    fl.resize(10, 99);

    for (auto e : fl) {
        cout << e << " ";
    }
    cout << endl;
}