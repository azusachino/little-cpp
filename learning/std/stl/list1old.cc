#include <iostream>
#include <list>

using namespace std;

int main() {
    list<char> l;

    for (char c = 'a'; c <= 'z'; ++c) {
        l.push_back(c);
    }
    list<char>::const_iterator pos;
    // 使用前置式递增（preincrement），因为它比后置式递增（postincrement）效率高。
    // 后者内部需要一个临时对象，因为它必须存放迭代器的原本位置并返回之，所以一般情况下最好使用++pos，不要用pos++。
    for (pos = l.begin(); pos != l.end(); ++pos) {
        cout << *pos << endl;
    }
}