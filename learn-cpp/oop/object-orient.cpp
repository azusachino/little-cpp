#include <iostream>

// 定义一个类
class Point {
    // 成员变量
    int x, y;
public: // 访问修饰符 private/protected/public
    Point(int a, int b) {
        x = a;
        y = b;
    }

    // 成员方法
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

struct B : A {
    char b;
};

struct C : public A {
    char c;
};

int main() {
    Point point; // 声明对象
    C c{};
    c.c = 1;
}