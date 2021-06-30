template <typename InputIterator, typename T>
inline InputIterator find_before(InputIterator first, InputIterator last,
                                 const T& val) {
    if (first == last) {
        return first;
    }
    InputIterator next(first);
    ++next;
    while (next != last && !(*next == val)) {
        ++next;
        ++first;
    }
    return first;
}

template <typename InputIterator, typename Pre>
inline InputIterator find_before_if(InputIterator first, InputIterator last,
                                    Pre predicate) {
    if (first == last) {
        return first;
    }
    InputIterator next(first);
    ++next;
    while (next != last && !predicate(*next)) {
        ++next;
        ++first;
    }
    return first;
}
