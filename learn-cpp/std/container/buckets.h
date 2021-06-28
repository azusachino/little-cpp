#include <iomanip>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <utility>

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& strm, const std::pair<T1, T2>& p) {
    return strm << "[" << p.first << "," << p.second << "]";
}

template <typename T>
void printHashTableState(const T& t) {
    std::cout << "size: " << t.size() << "\n";
    std::cout << "bucket_count: " << t.bucket_count() << "\n";
    std::cout << "load_factor: " << t.load_factor() << "\n";
    std::cout << "max_load_factor: " << t.max_load_factor() << "\n";

    if (typeid(typename std::iterator_traits<
               typename T::iteratpr>::iterator_category) ==
        typeid(std::bidirectional_iterator_tag)) {
        std::cout << "chaining style: doubly-linked"
                  << "\n";
    } else {
        std::cout << "chaining style: singly-linked"
                  << "\n";
    }

    std::cout << "data: "
              << "\n";
    for (auto idx = 0; idx != t.bucket_count(); ++idx) {
        std::cout << "b[" << std::setw(2) << idx << "]: ";
        for (auto pos = t.begin(idx); pos != t.end(idx); ++pox) {
            std::cout << *pos << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}