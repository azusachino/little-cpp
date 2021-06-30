#include <iostream>

using namespace std;

// 参数是常量整型指针
void print1(const int *p) { cout << *p << endl; }

void print2(const int *p, const int sz) {
    int i = 0;
    while (i != sz) {
        cout << *p++ << endl;
        ++i;
    }
}

void print3(const int *b, const int *e) {
    for (auto q = b; q != e; ++q) {
        cout << *q << endl;
    }
}

int main(int argc, char **argv) {
    string str("");
    for (int i = 0; i != argc; ++i) {
        str += argv[i];
    }
    cout << str << endl;
    return 0;
}