#include <iostream>

using namespace std;

#include "str-blob.h"

int main() {
    StrBlob sb1;
    {
        StrBlob sb2 = {"a", "b", "c"};
        sb1 = sb2;
        sb2.push_back("about");
        cout << sb2.size() << endl;
    }
    cout << sb1.size() << endl;

    return 0;
}