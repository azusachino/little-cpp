#include <iostream>
#include <unordered_set>

#include "buckets.h"

int main() {
    std::unordered_set<int> is = {1, 3, 5, 7, 9, 11, 13, 17, 19};
    printHashTableState(is);
    is.insert({-7, 17, 33, 4});
    printHashTableState(is);
}