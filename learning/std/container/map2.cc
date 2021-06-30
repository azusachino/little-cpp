#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    typedef map<string, float> StringFloatMap;

    StringFloatMap m;

    m["BASF"]    = 369.50;
    m["VW"]      = 413.50;
    m["Daimler"] = 819.00;
    m["BMW"]     = 834.00;
    m["Siemens"] = 842.20;

    StringFloatMap::iterator pos;
    cout << left;
    for (pos = m.begin(); pos != m.end(); ++pos) {
        cout << "stock: " << setw(12) << pos->first << "price: " << pos->second
             << endl;
    }
    cout << endl;
    for (pos = m.begin(); pos != m.end(); ++pos) {
        pos->second *= 2;
    }
    for (pos = m.begin(); pos != m.end(); ++pos) {
        cout << "stock: " << setw(12) << pos->first << "price: " << pos->second
             << endl;
    }
    cout << endl;

    m["Volkswagen"] = m["VW"];
    m.erase("VW");

    for (pos = m.begin(); pos != m.end(); ++pos) {
        cout << "stock: " << setw(12) << pos->first << "price: " << pos->second
             << endl;
    }
    cout << endl;
}