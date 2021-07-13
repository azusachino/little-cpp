#include <iostream>

using namespace std;

istream &operator>>(istream &is, Date &dt)
{
    is >> dt.year >> dt.month >> dt.day;
    if (!is)
    {
        dt = Date(0, 0, 0);
    }
    return is;
}

class Date
{
public:
    Date() {}
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    Date &operator=(const std::string &date);
    friend istream &operator>>(istream &is, Date &dt);

private:
    int year, month, day;
};

// Date &Date::operator=(const std::string &date)
// {
//     std::istringstream in(date);
//     char ch1, ch2;
//     in >> year >> ch1 >> month >> ch2 >> day;
//     if (!in || ch1 != '-' || ch2 != '-')
//     {
//         throw std::invalid_argument("bad date");
//     }

//     return *this;
// }