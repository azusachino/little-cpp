#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> coll;

    for (int i = 0; i <= 6; ++i) {
        coll.push_back(i);
    }

    for (int i = 0; i < coll.size(); ++i) {
        cout << coll[i] << endl;
    }
}