#include <memory>

using namespace std;

class A {
private:
    int val;

public:
    A(int val) : val(val) {}
};

// old fashioned
class B {
private:
    A* ptr1;
    A* ptr2;

public:
    // constructor taht initializes the pointers
    // will cause resource leak if second new throws
    B(int val1, int val2) : ptr1(new A(val1)), ptr2(new A(val2)) {}

    // copy constructor
    // might cause resource leak if second new throws
    B(const B& x) : ptr1(new A(*x.ptr1)), ptr2(new A(*x.ptr2)) {}

    // assignment operator
    const B& operator=(const B& x) {
        *ptr1 = *x.ptr1;
        *ptr2 = *x.ptr2;
        return *this;
    }

    ~B() {
        delete ptr1;
        delete ptr2;
    }
};

// use unique ptr
class C {
private:
    unique_ptr<A> ptr1;
    unique_ptr<A> ptr2;

public:
    C(int val1, int val2) : ptr1(new A(val1)), ptr2(new A(val2)) {}

    // copy constructor
    C(const C& x) : ptr1(new A(*x.ptr1)), ptr2(new A(*x.ptr2)) {}

    // assignment operator
    const C& operator=(const C& x) {
        *ptr1 = *x.ptr1;
        *ptr2 = *x.ptr2;
        return *this;
    }
    // no destructor necessary
};