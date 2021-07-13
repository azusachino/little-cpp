#include <iostream>

// 定义or声明
extern int ix = 1024;  //定义
int        iy;         // 声明+定义
extern int iz;         // 声明

int main() {
    minus();
    return 0;
}

// demonstrate minus with unsigned int
void minus() {
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;  // 32
    // u和u2都是无符号整数，因此u2-u得到了正确的结果（42-10=32）；
    // u-u2也能正确计算，但是因为直接计算的结果是-32，所以在表示为无符号整数时自动加上了模，
    // 在作者的编译环境中int占32位，因此加模的结果是4294967264。
    std::cout << u - u2 << std::endl;  // 4284867264

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;  // 32
    std::cout << i - i2 << std::endl;  // -32
    std::cout << i - u << std::endl;   // 0
    std::cout << u - i << std::endl;   // 0
}

void number_type() {
    // (a)'a'表示字符a，L'a'表示宽字符型字面值a且类型是wchar_t，＂a＂表示字符串a，L＂a＂表示宽字符型字符串a。
    // (b)10是一个普通的整数类型字面值，10u表示一个无符号数，10L表示一个长整型数，10uL表示一个无符号长整型数，012是一个八进制数（对应的十进制数是10），0xC是一个十六进制数（对应的十进制数是12）。
    // (c)3.14是一个普通的浮点类型字面值，3.14f表示一个float类型的单精度浮点数，3.14L表示一个long
    // double类型的扩展精度浮点数。
    // (d)10是一个整数，10u是一个无符号整数，10.是一个浮点数，10e-2是一个科学计数法表示的浮点数，大小为10*10-2=0.1。
    // auto a = 'a', b = L'a', c = "a", d = L"a";
    // auto e = 10, f = 10u, g = 10L, h = 10uL, i = 012, j = 0xC;
    // auto k = 3.14, l = 3.14f, m = 3.14L;
    // auto n = 10, o = 10u, p = 10., q = 10e-2;
}
