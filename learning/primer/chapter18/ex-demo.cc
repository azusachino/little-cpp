#include <exception>
#include <vector>
#include <iostream>

using namespace std;

void exercise(int* b, int* e) {
    vector<int> v(b, e);
    int* p = new int[v.size()];
    ifstream in("ints");
    // cause exception will cause memory leak
}

void exercise1() {
    int* p = new int[2];
    try {
        ifstream in("ints");

    }
    catch {
        delete p; // release array
    }
}

class Resource {
public:
    Resource(size_t sz) : r(new int[sz]) {}
    ~Resource() {
        if (r) {
            delete r;
        }
    }
private:
    int* r;
};

void exercise2() {
    Resource res(2);
    ifstream in("ints");
    // exception occurs here
    // c++保证Resource析构函数一定会执行
}

void tryCatch() {
    try {

    }
    catch (overflow_error eo) {

    }
    catch (const runtime_error& re) {
                    
    }
    catch (exception) {

    }
}