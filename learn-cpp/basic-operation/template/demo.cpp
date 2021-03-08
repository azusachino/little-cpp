//
// Created by ycpang on 2021/1/13.
//
namespace std;

template<class T>
T GetMax(T a, T b) {
    T result;
    result = (a > b) ? a : b;
    return (result);
}

template<class G>
G GetMin(G c, G d) {
    G ret;
    ret = (c > d) ? d : c;
    return (ret);
};

void test() {
    int i = 5, j = 6, k;
    // 生成int类型的函数
    k = GetMax<int>(i, j);

    long l = 10, m = 5, n;
    // 生成long类型的函数
    n = GetMax<long>(l, m);

}