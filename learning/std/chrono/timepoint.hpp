#include <chrono>
#include <ctime>
#include <string>

using namespace std;

inline string asString(const chrono::system_clock::time_point& tp) {
    time_t t  = chrono::system_clock::to_time_t(tp);
    string ts = ctime(&t);
    ts.resize(ts.size() - 1);
    return ts;
}

inline chrono::system_clock::time_point makeTimePoint(int year, int month,
                                                      int day, int hour,
                                                      int min, int sec = 0) {
    struct std::tm t;
    t.tm_sec  = sec;
    t.tm_min  = min;
    t.tm_hour = hour;
    t.tm_mday = day;
    t.tm_mon  = month;
    t.tm_year = year;
    time_t tt = mktime(&t);
    if (tt == -1) {
        throw "no valid system time";
    }
    return chrono::system_clock::from_time_t(tt);
}