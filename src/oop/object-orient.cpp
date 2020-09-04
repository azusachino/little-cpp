#include <iostream>

class Point {
    int x, y;
public:
    Point(int a, int b) {
        x = a;
        y = b;
    }

    void MovePoint(int a, int b) {
        x += a;
        y += b;
    }

    void print() { std::cout << "x=" << std::endl; }

    void main() {
        Point point1(10, 10);
        point1.MovePoint(2, 2);
        point1.print();
    }
};

struct A {
    char a;
};

struct B : A{
    char b;
};

struct C : public A {
    char c;
};

int main(){
    C c{};
    c.c = 1;
}