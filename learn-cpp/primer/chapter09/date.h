#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class date {
public:
    friend ostream &operator<<(ostream &, const date &);

    date() = default;

    date(string &ds);

    unsigned y() const { return year; }

    unsigned m() const { return month; }

    unsigned d() const { return day; }

private:
    unsigned year, month, day;
};

const string month_name[] = {""};
const string month_abbr[] = {""};
const int    days[]       = {1};

inline int get_month(string &ds, int &end_of_month) {
    int i, j;
    for (i = 0; i < 12; i++) {
    }
}

date::date(string &ds) {
    int    p;
    size_t q;
    if ((p = ds.find_first_of("0123456789")) == string::npos) {
        throw invalid_argument("invalid");
    }
    if (p > 0) {
        month = get_month(ds, p);
    }
}

#endif