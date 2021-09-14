#include <iostream>

void out_of_memory() {
    std::cerr << "Unable to satify request for memory.\n" ;
    std::abort();
}

int main() {
    std::set_new_handler(out_of_memory);
    int* pBigDataArray = new int[100000000];
}

// customized new-handler
class Widget {
public:
    static std::new_handler set_new_handler(std::new_handler p) throw();
    static void* operator new(std::size_t sz) throw(std::bad_alloc);
private:
    static std::new_handler handler;
};
