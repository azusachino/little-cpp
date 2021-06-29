//
// Created by ycpang on 2021-02-01.
//

// #define 预处理指令用于创建符号常量。该符号常量通常称为宏，指令的一般形式是：
//
// #define macro-name replacement-text
#include <iostream>

using namespace std;

#define PI 3.14159

int main() {
    cout << "Value of PI :" << PI << endl;

    return 0;
}

// 参数宏
#define MIN(a, b) (a > b ? a : b)

// 条件编译
#ifdef DEBUG
cerr << "variable x =" << x << endl;
#endif

using namespace std;
#define DEBUG

int __main() {
    int i, j;
    i = 100;
    j = 30;
#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

#if 0
    /* 这是注释部分 */
   cout << MKSTR(HELLO C++) << endl;
#endif

    cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: Coming out of main function" << endl;
#endif
    return 0;
}

int main() {
    cout << "Value of __LINE__ : " << __LINE__
         << endl;  // 这会在程序编译时包含当前行号。
    cout << "Value of __FILE__ : " << __FILE__
         << endl;  // 这会在程序编译时包含当前文件名。
    cout << "Value of __DATE__ : " << __DATE__
         << endl;  // 这会包含一个形式为 month/day/year
                   // 的字符串，它表示把源文件转换为目标代码的日期。
    cout << "Value of __TIME__ : " << __TIME__
         << endl;  // 这会包含一个形式为 hour:minute:second
                   // 的字符串，它表示程序被编译的时间。
    return 0;
}