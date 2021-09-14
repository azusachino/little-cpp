#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, float> mp;

    mp["VAT1"] = 0.16;
    mp["VAT2"] = 0.07;
    mp["an arbitrary number"] = 4983.223;
    mp["NULL"] = 0;

    mp["VAT1"] += 0.03;

    cout << "VAT difference: " << mp["VAT1"] - mp["VAT2"] << endl;
}