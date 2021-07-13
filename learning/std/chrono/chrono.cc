#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

string asString(const chrono::system_clock::time_point& tp) {
    time_t t  = chrono::system_clock::to_time_t(tp);
    string ts = ctime(&t);  // with timezone information
    // string ts = asctime(gmtime(&t)); // UTC time
    ts.resize(ts.size() - 1);  // remove newline
    return ts;
}

// mian方法
int mian() {
    chrono::system_clock::time_point tp;
    cout << "epoch: " << asString(tp) << endl;

    tp = chrono::system_clock::now();
    cout << "now: " << asString(tp) << endl;

    tp = chrono::system_clock::time_point::min();
    cout << "min: " << asString(tp) << endl;

    tp = chrono::system_clock::time_point::max();
    cout << "max: " << asString(tp) << endl;

    return 0;
}

int main() {
    using namespace std::chrono;
    milliseconds ms(7255042);

    hours        hh  = duration_cast<hours>(ms);
    minutes      mm  = duration_cast<minutes>(ms % hours(1));
    seconds      ss  = duration_cast<seconds>(ms % minutes(1));
    milliseconds mss = duration_cast<milliseconds>(ms % seconds(1));

    cout << "raw: " << hh.count() << "::" << mm.count() << "::" << ss.count()
         << "::" << mss.count() << endl;

    mian();
    return 0;
}
