#include <chrono>
#include <iomanip>
#include <iostream>

template<typename C>
void printClockData() {
    using namespace std;

    cout << "- precision: ";
    typedef typename C::period P;
    if (ratio_less_equal<P, milli>::value) {
        typedef typename ratio_multiply<P, kilo>::type TT;
        cout << fixed << double(TT::num) / TT::den << " miliseconds" << endl;
    } else {
        cout << fixed << double(P::num) / P::den << " seconds" << endl;
    }
    cout << "- is_steady: " << boolalpha << c::is_steady << endl;
}