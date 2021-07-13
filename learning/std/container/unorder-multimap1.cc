#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

#include "buckets.h"

using namespace std;

int main() {
    unordered_multimap<string, string> dict = {{"day", "Tag"}};
    printHashTableState(dict);

    dict.insert(
        {{"smart", "raffiniert"}, {"smart", "klug"}, {"clever", "raffiniert"}});
    printHashTableState(dict);
    dict.max_load_factor(0.75);
    printHashTableState(dict);
}