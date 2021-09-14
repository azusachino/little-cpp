#include <algorithm>
#include <iostream>

using namespace std;

bool int_ptr_less(int *a, int *b) { return *a < *b; }

int main() {
    int x = 16;
    int y = 42;
    int z = 33;
    int *px = &x;
    int *py = &y;
    auto pz = &z;

    int *pmax = std::max(px, py, int_ptr_less);

    std::pair<int *, int *> extremes = std::minmax({px, py, pz}, int_ptr_less);

    auto ex = std::minmax({px, py, pz}, [](int *a, int *b) { return *a < *b; });
    cout << *pmax << endl;
    // cout << extremes << endl;

    return 0;
}
