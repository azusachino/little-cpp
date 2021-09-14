#include <iostream>

using namespace std;

using namespace std;

int main() {
    double *pvalue = nullptr;        // 初始化为 null 的指针
    pvalue = new double;  // 为变量请求内存

    *pvalue = 29494.99;  // 在分配的地址存储值
    cout << "Value of pvalue : " << *pvalue << endl;

    delete pvalue;  // 释放内存

    return 0;
}

// 如果自由存储区已被用完，可能无法成功分配内存。

int checkNull() {
    //    double *pvalue = NULL;
    //    if (!(pvalue = new double)) {
    //        cout << "Error: out of memory." <<
    //             endl;
    //        exit(1);
    //
    //    }
    return 0;
}

int main_() {
    int **p;
    int i, j;  // p[4][8]
    //开始分配4行8列的二维数据
    p = new int *[4];
    for (i = 0; i < 4; i++) {
        p[i] = new int[8];
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            p[i][j] = j * i;
        }
    }
    //打印数据
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if (j == 0) cout << endl;
            cout << p[i][j] << "\t";
        }
    }
    //开始释放申请的堆
    for (i = 0; i < 4; i++) {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}

class Box {
public:
    Box() { cout << "调用构造函数！" << endl; }

    ~Box() { cout << "调用析构函数！" << endl; }
};

int main__() {
    Box *myBoxArray = new Box[4];

    delete[] myBoxArray;  // 删除数组
    return 0;
}