#include <iostream>
#include "my_math.h"

using namespace std;

int main(int argc, char const *argv[])
{
    double a = add(1.1, 1.2);
    int b = add(1, 2);
    cout << "double result is " << a << endl;
    cout << "int result is " << b << endl;
    return 0;
}