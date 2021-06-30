#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {
    allocator<string> alloc;
    // 分配100个未初始化的string
    auto const p = alloc.allocate(100);

    string  s;
    string *q = p;  // q指向第一个string
    while (cin >> s && q != p + 100) {
        alloc.construct(q++, s);
    }
    const size_t sz = q - p;

    for (size_t i = 0; i < sz; ++i) {
        cout << p[i] << " " << endl;
    }
    while (q != p) {  // 释放已构造的string
        alloc.destroy(--q);
    }
    alloc.deallocate(p, 100);  // 释放内存

    return 0;
}