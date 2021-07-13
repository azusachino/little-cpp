#include <cmath>
#include <iostream>
#include <string>

#include "chapter06.h"

using namespace std;

int fact(int val) {
    if (val < 0) {
        return -1;
    }
    int ret = 1;
    for (int i = 1; i <= val; ++i) {
        ret *= i;
    }
    return ret;
}

double myAbs2(double d) { return abs(d); }

// 在函数体内部通过解引用操作改变指针所指的内容
void mySwap(int *p, int *q) {
    int temp = *p;
    *p       = *q;
    *q       = temp;
}

// 错误的做法：在函数内部交换了两个形参指针本身的值，未能影响实参
void mySwapWrong(int *p, int *q) {
    int *tmp = p;  // tmp是一个指针
    p        = q;
    q        = tmp;
}

void mySwap2(int &p, int &q) {
    int tmp = p;
    p       = q;
    q       = tmp;
}

// 无需改变str，使用常量引用
bool hasUpper(const string &str) {
    for (auto c : str) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

// 需要修改参数的内容
void changeToLower(string &str) {
    for (auto &c : str) {
        c = tolower(c);
    }
}