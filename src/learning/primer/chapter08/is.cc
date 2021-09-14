#include <iostream>
#include <stdexcept>

using namespace std;

istream &f(istream &in) {
    int v;
    while (in >> v, !in.eof()) {
        if (in.bad()) {
            throw runtime_error("io error");
        }
        if (in.fail()) {
            cerr << "data error" << endl;
            in.clear();
            in.ignore(100, '\n');
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main() {
    cout << "please input some numbers, end with ctrl + z" << endl;
    f(cin);
    return 0;
}