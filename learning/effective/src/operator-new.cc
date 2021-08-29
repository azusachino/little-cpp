#include <new>
#include <memory>

void* operator new(std::size_t sz) throw(std::bad_alloc) {
    using namespace std;
    if (sz == 0){
        sz = 1;
    }
    void* p;
    while (true) {
        if ((p = malloc(sz)) != nullptr) {
            return p;
        }
        new_handler handler = set_new_handler(0);
        set_new_handler(handler);

        if (handler) {
            (*handler)();
        } else {
            throw std::bad_alloc();
        }
    }
}