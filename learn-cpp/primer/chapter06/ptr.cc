#include <iostream>

using namespace std;

// 既不交换指针，也不交换指针指的内容
void swap1(int *p, int *q) {
    int *tmp = p;
    p = q;
    q = tmp;
}

// 交换指针所指的内容
void swap2(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *p = tmp;
}

// 交换指针所指的内存地址
void swap3(int *&p, int *&q) {
    int *tmp = p;
    p = q;
    q = tmp;
}