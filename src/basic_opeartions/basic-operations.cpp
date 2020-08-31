#include "BasicOperate.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class test;

int main() {
    std::cout << "" << std::endl;
    auto ptr = new shape;
    delete ptr; // help gc
    for (;;)
        break;
    [] {}; // 最简单的lambda
    auto basicLambda = [] { cout << "Hello Lambda!" << endl; };

    basicLambda();

    std::vector<int> v = {1, 2, 3, 4, 5};
    int even_count = 0;
    std::count_if(v.begin(), v.end(), [&even_count](int val) {
        if (!(val & 1)) {
            ++even_count;
        }
    });
    // 数字定义
    short s = 10;
    int i = -1000;
    long l = 100000;
    float f = 230.47;
    double d = 200.374;

    // 数学运算
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(f) << endl;
    cout << "sqrt(f) :" << sqrt(l) << endl;
    cout << "pow( d, 2) :" << pow(s, 2) << endl;

    // 数组
    double balance[10];
    double another[] = {1.2, 3, 2, 3};

    // 字符串
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char greet[] = "Hello";

    char str1[11] = "Hello"; string string1 = "Hello";
    char str2[11] = "World";
    char str3[11];
    int  len ;

    // 复制 str1 到 str3
    strcpy( str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;

    // 连接 str1 和 str2
    strcat( str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;

    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;
}

class test {
public:
    test() = default;

    ~test() = default;

    void hello() {
        cout << "test hello!n";
    };

    void lambda() {
        auto fun = [this] { // 捕获了 this 指针
            this->hello(); // 这里 this 调用的就是 class test 的对象了
        };
        fun();
    }
};
