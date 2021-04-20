#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector<int> vec;
    srand((unsigned) time(NULL));
    cout << "we will generate some elements..." << endl;
    for (int i = 0; i != 10; ++i) {
        vec.push_back(rand() % 100);
    }
    cout << *vec.begin() << endl;
    cout << *(vec.begin()) << endl;
    cout << *vec.begin() + 1 << endl;
    cout << (*(vec.begin())) + 1 << endl;

    return 0;
}

void secretConvert() {
    char cval;
    int ival;
    unsigned int ui;
    float fval;
    double dval;

    cval = 'a' + 3;            // 字符'a'提升为int，与3相加所得的结果再转换为char并赋给cval。
    fval = ui - ival * 1.0;    // ival转换为double，与1.0相乘的结果也是double类型，ui转换为double类型后与乘法得到的结果相减，最终的结果转换为float并赋给fval。
    dval = ui * fval;          // ui转换为float，与fval相乘的结果转换为double类型并赋给dval。
    cval = ival + fval + dval; // ival转换为float，与fval相加所得的结果转换为double类型，再与dval相加后结果转换为char类型。
}

void convert() {
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;
    pv = (void *) ps;
    pv = static_cast<void *>(const_cast<string *>(ps));
    i = int(*pc);
    i = static_cast<int>(*pc);
    pv = &d;
    pv = static_cast<void *>(&d);
    pc = (char *) pv;
    pc = static_cast<char *>(pv);
}

void loop() {
    constexpr int sz = 5;
    int ia[sz] = {1, 2, 3, 4, 5};
    for (int *ptr = ia, ix = 0; ix != sz && ptr != ia + sz; ++ix, ++ptr) {
        cout << *ptr << endl;
    }
}
