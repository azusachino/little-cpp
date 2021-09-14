# 模板与泛型编程

## 定义模板

```c++
template <typename T>
inline int compare(const T& v1, const T& v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```

编译器用推断出的模板参数来为我们实例化（instantiate）一个特定版本的函数。

```c++
template <typename T> T foo(T* p) {
    T tmp = *p;
    return tmp;
}
// wrong expr
template <typename T, U> T calc(const T&, const U&);
// collect expr
template<typename T, class U> calc(const T&, const U&);

// 类型无关和可移植性
template <typename T> int compare(const T& v1, const T& v2) {
    if (less<T>()(v1, v2)) return -1;
    if (less<T>()(v2, v2)) return 1;
    return 0;
}
```

### 类模板

[my-template](my-template.h)

### 默认模板实参

```c++
template <typename T, typename F=less<T>>
inline int compare(const T& v1, const T& v2, F f= F()) {
    if (f(v1 < v2)) return -1;
    if (f(v2 < v1)) return 1;
    return 0;
}
```

### 成员模板

```c++
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr):os(s) {}
    template <typename T> void operator()(T *p) const {
        os << "delete unique_ptr " << std::endl; delete p;
    }
private:
    std::ostream &os;
};
```

### 控制实例化

在多个文件中实例化相同模板的额外开销可能非常严重。在新标准中，我们可以通过显式实例化（explicit instantiation）来避免这种开销。

```c++
extern template class Blob<string>;
extern template int compare(const int&, const int&);

Blob<string> sa1, sa2;
Blob<int> a1 = {0,1,2,3,4,5,6,7,8,9};
Blob<int> a2(a1);
int i = compare(a1[0], a2[9]);
```

## 模板实参推断

```c++
template <typename T> T fobj(T,T); // copy
template <typename T> T fref(const T&, const T&); // ref

string s1("a value");
const string s2("another value");

fobj(s1, s2); // ok
fref(s1, s2); // ok

int a[10], b[42];
fobj(a,b); // call f(int*, int*);
fref(a,b); // wrong,
```

### 函数模板显式实参

```c++
template <typename T1, typename T2, typename T3>
T1 sum(T2, T3);

auto val3 = sum<long long>(i, lng); // long long sum(int, long);
```

显式模板实参按由左至右的顺序与对应的模板参数匹配；第一个模板实参与第一个模板参数匹配，第二个实参与第二个参数匹配，依此类推。

### 尾置返回类型与类型转换

```c++
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg) {
    return *beg;
}
```

### 函数指针和实参推断

```c++
template <typename T> int compare(const T&, const T&);

int (*pf1)(const int&, const int&) = compare;
```

### 模板实参推断和引用

### std::move

```c++
template <typename T
template remove_reference<T>::type&& move(T&& t) {
    return static_cast<typename remove_reference<T>::type&&>(t);
}
```

## 重载与模板

函数模板可以被另一个模板或一个普通非模板函数重载。

```c++
template <typename T> string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> string debug_rep(T *p) {
    ostringstream ret;
    ret << "pointer: " << p;
    if (p) {
        ret << " " << debug_rep(*p);
    } else {
        ret << " null pointer";
    }
    return ret.str();
}
```

## 可变参数模板

一个可变参数模板（variadic template）就是一个接受可变数目参数的模板函数或模板类。可变数目的参数被称为参数包（parameter packet）。存在两种参数包：模板参数包（template parameter
packet），表示零个或多个模板参数；函数参数包（function parameter packet），表示零个或多个函数参数。

```c++
template <typename T, typename ...Args>
void foo(const T &t, const Args& ... rest);
```
