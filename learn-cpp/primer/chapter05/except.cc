#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    substract(1, 0);
    return 0;
}

void substract(int a, int b) {
    if (b == 0) {
        throw runtime_error("cannot be zero");
    }
    cout << a / b << endl;
}

void substract2(int a, int b) {
    try {
        if (b == 0) {
            throw runtime_error("Cannot be zero");
        }
        cout << a / b << endl;
    }
    catch (runtime_error e) {
        cout << "catched error " << e.what() << endl;
    }
}