#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cout << "default bool values: " << true << " " << false
         << "\n alpha bool values: " << boolalpha << true << " " << false
         << noboolalpha << endl;

    // 在输出中指出进制
    cout << showbase;
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "octal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;
    cout << noshowbase;

    // 设置精度
    cout << "Precision: " << cout.precision() << ", value: " << sqrt(2.0)
         << endl;
    cout.precision(12);
    cout << "Precision: " << cout.precision() << ", value: " << sqrt(2.0)
         << endl;
    cout.precision(3);
    cout << "Precision: " << cout.precision() << ", value: " << sqrt(2.0)
         << endl;

    cout << "default format: " << 100 * sqrt(2.0) << '\n'
         << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
         << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
         << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << '\n'
         << endl;

    // 打印小数点
    cout << 10.0 << endl;
    cout << showpoint << 10.0 << noshowpoint << endl;

    // 输出补白
    int    i = -16;
    double d = 3.14159;

    cout << "i: " << setw(12) << i << "next col" << '\n'
         << "d: " << setw(12) << d << "next col" << '\n';
    cout << left << right << internal << setfill('#') << setfill(' ');

    // 跳过空格以及可能的制表符和换行符
    cin >> noskipws;
    // while(cin >> ch) {
    //     cout << ch;
    // }
    cin >> skipws;
    return 0;
}