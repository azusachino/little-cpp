#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

bool isPrime(int number) {
    number = abs(number);
    if (number == 0 || number == 1) {
        return false;
    }
    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor) {
        ;
    }
    return divisor == 1;
}

int main() {
    list<int> l;
    for (int i = 24; i <= 30; ++i) {
        l.push_back(i);
    }
    auto pos = find_if(l.cbegin(), l.cend(), isPrime);
    if (pos != l.end()) {
        cout << *pos << " is first prime number found" << endl;
    } else {
        cout << "no prime number found " << endl;
    }
}