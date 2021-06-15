#include <chrono>
#include <iostream>

using namespace std;

int main() {
    using namespace std::chrono;
    milliseconds ms(7255042);

    hours        hh  = duration_cast<hours>(ms);
    minutes      mm  = duration_cast<minutes>(ms % hours(1));
    seconds      ss  = duration_cast<seconds>(ms % minutes(1));
    milliseconds mss = duration_cast<milliseconds>(ms % seconds(1));

    cout << "raw: " << hh.count() << "::" << mm.count() << "::" << ss.count()
         << "::" << mss.count() << endl;

    return 0;
}