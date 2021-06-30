#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = intVector();
    for (auto m : v) {
        cout << m << " ";
    }
    cout << endl;

    vector<string> v2 = strVector();
    for (auto &r : v2) {
        for (auto &c : r) {
            c = toupper(c);
        }
        cout << r << endl;
    }
}

vector<int> intVector() {
    vector<int> v;
    int         i;
    char        ctrl;
    while (cin >> i) {
        v.push_back(i);
        cout << "are you sure to continue? (y or n)" << endl;
        cin >> ctrl;
        if (ctrl != 'y' && ctrl != 'Y') break;
    }
    return v;
}

vector<string> strVector() {
    vector<string> v;
    string         i;
    char           ctrl;
    while (cin >> i) {
        v.push_back(i);
        cout << "are you sure to continue? (y or n)" << endl;
        cin >> ctrl;
        if (ctrl != 'y' && ctrl != 'Y') break;
    }
    return v;
}

void addLeftAndRight() {
    vector<int> v;
    int         val;
    cout << "" << endl;
    while (cin >> val) {
        v.push_back(val);
    }
    if (v.size() == 0) {
        cout << "empty vector" << endl;
    }
    cout << "print sum: " << endl;
    for (decltype(v.size()) i = 0; i < v.size() / 2; i++) {
        cout << v[i] + v[v.size() - i - 1] << " ";
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
    if (v.size() % 2 != 0) {
        cout << v[v.size() / 2];
    }
}

void modifyVector() {
    vector<int> v;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 1000);
    }
    cout << "generated random numbers are: " << endl;
    for (auto it = v.cbegin(); it != v.cend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "after multiply 10: " << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        *it *= 10;
        cout << *it << " ";
    }
    cout << endl;
}

void initVector() {
    vector<int>    v1;            // size 0
    vector<int>    v2(10);        // size 10, elem 0
    vector<int>    v3(10, 42);    // size 10, elem 42
    vector<int>    v4{10};        // size 1, elem 10
    vector<int>    v5{10, 42};    // size 2, elem 10, 42
    vector<string> v6{10};        // size 10, elem ""
    vector<string> v7{10, "h1"};  // size 10, elem "hi"
}
