#include <forward_list>

#include "find-before.h"
#include "print.h"

using namespace std;

int main() {
    forward_list<int> list      = {1, 2, 3, 4, 5, 97, 97, 99};
    auto              posBefore = list.before_begin();
    for (auto pos = list.begin(); pos != list.end(); ++pos, ++posBefore) {
        if (*pos % 2 == 0) {
            break;
        }
    }
    list.insert_after(posBefore, 42);
    PRINT_ELEMENTS(list);

    auto posBefore1 = find_before_if(list.before_begin(), list.end(),
                                     [](int i) { return i % 2 == 0; });
}