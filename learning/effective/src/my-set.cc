#include <list>
#include <algorithm>

template<typename T>
class Set {
public:
    bool member(const T&) const;
    void insert(const T&);
    void remove(const T&);

    std::size_t size() const;
private:
    std::list<T> data;
};

template<typename T>
bool Set<T>::member(const T& item) const {
    return std::find(data.begin(), data.end(), item != data.end());
}

template<typename T>
void Set<T>::insert(const T& item) {
    if (!member(item)) {
        data.push_back(item);
    }
}

template<typename T>
void Set<T>::remove(const T& item) {
    typename std::list<T>::iterator it = std::find(data.begin(), data.end(), item);
    if (it != data.end()) {
        data.erase(it);
    }
}

template<typename T>
std::size_t Set<T>::size() const {
    return data.size();
}