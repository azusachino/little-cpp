#include "new-handler-holder.h"

template <typename T>
class NewHandlerSupport {
public:
    static std::new_handler set_new_handler(std::new_handler nh) throw();
    static void* operator new(std::size_t size) throw(std::bad_alloc);

private:
    std::new_handler current_handler;
};

template <typename T>
std::new_handler NewHandlerSupport<T>::set_new_handler(
    std::new_handler nh) throw() {
    std::new_handler old = current_handler;
    current_handler      = nh;
    return old;
}

template <typename T>
void* NewHandlerSupport<T>::operator new(std::size_t size) throw(
    std::bad_alloc) {
    NewHandlerHolder h(std::set_new_handler(current_handler));
    return ::        operator new(size);
}

template <typename T>
std::new_handler NewHandlerSupport<T>::current_handler = 0;