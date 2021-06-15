# Common Tool

## Pari & Tuple

### Pair

Class pair 可将两个 value 视为一个单元。C++标准库内多处用到了这个 class。尤其容器 map、multimap、unordered_map 和 unordered_multimap 就是使用 pair 来管理其以 key/value pair 形式存在的元素。任何函数如果需返回两个 value，也需要用到 pair，例如 minmax（）。

```c++
namespace std {
    template <typename T1, typename T2>
    struct pair {
        // member
        T1 first;
        T2 second;
    }
}
```

自 C++11 起，可以对 pair 使用一份 tuple-like 接口。因此，可以使用 tuple_size ＜＞：：value 获得元素个数，使用 tuple_element ＜＞：：type 获得某指定元素的类型，也可以使用 get（）获得 first 或 second

```c++
typedef std::pair<int, float> IntFloatPair;
IntFloatPair p(42, 3.14);

std::get<0>(p); // yields p.first
std::get<1>(p); // yields p.second
std::tuple_size<IntFloatPair>::value; // yields 2
std::tuple_element<0, IntFloatPair>::type; // yields int
```

Default 构造函数生成一个 pair 时，以两个“被 default 构造函数个别初始化”的元素作为初值。

```c++
namespace std {
    template <typename T1, typename T2>
    struct pair {
        pair(const T1& x, const T2& y); // move semantic
        template<typename U, typename V> pair(U&& x, V&& y); // support 隐式类型转换
        template <typename... Args1, typename... Args2>
          pair(piecewise_construct_t, tuple<Args1...> first_args, tuple<Args2...> second_args);
    }
}
```

便捷函数`make_pair`

```c++
void f(std::pair<int, const char*>);
void g(std::pair<const int, std::string>);

void foo() {
    f(std::make_pair(42, "empty"));
    g(std::make_pair(42, "chair"));

    f({42, "empty"});
    g({42, "chair"});
}
```

### tuple

- 通过声明，或使用便捷函数 make_tuple（），你可以创建一个 tuple。
- 通过 get ＜＞（） function template，你可以访问 tuple 的元素。

如果想方便地在 tuple 中使用 reference，可选择 tie（），它可以建立一个内含 reference 的 tuple

```c++
std::tuple <int, float, std::string> t(77, 1.1, "more light");
int i;
float f;
std::string s;
std::tie(i,f,s) = t; // assigns values of t to i,f,s
std::tie(i. std::ignore, s);
```

其他 tuple 特性：

- tuple_size ＜ tupletype ＞：：value 可获得元素个数。
- tuple_element ＜ idx，tupletype ＞：：type 可取得第 idx 个元素的类型（也就是 get（）返回值的类型）。
- tuple_cat（）可将多个 tuple 串接成一个 tuple。

## Smart Pointer

所有 smart pointer class 都被定义于头文件＜ memory ＞内。

1. Class shared_ptr 实现共享式拥有（shared ownership）概念。多个 smartpointer 可以指向相同对象，该对象和其相关资源会在“最后一个 reference 被销毁”时被释放。为了在结构较复杂的情境中执行上述工作，标准库提供了 weak_ptr、bad_weak_ptr 和 enable_shared_from_this 等辅助类。
2. Class unique_ptr 实现独占式拥有（exclusive ownership）或严格拥有（strictownership）概念，保证同一时间内只有一个 smart pointer 可以指向该对象。你可以移交拥有权。它对于避免资源泄漏（resource leak）——例如“以 new 创建对象后因为发生异常而忘记调用 delete”——特别有用。

### shared_ptr

check source code [ptr1](./smart-pointer/sharedptr.cc)

- cann't assginment ptr, use `ptr.reset(xxx)`
- shared_ptr 提供的 default deleter 调用的是 delete，不是 delete[]

```c++
std::shared_ptr<int> p(new int[10]); // ERROR, but compiles
```

### weak_ptr

check source code [weakptr2](./smart-pointer/weakptr2.cc)

### 误用 Shared Pointer

check [weakptr3](./smart-pointer/weakptr3.cc)

### 细究 SharedPointer 和 WeakPointer

- atomic_is_lock_free(&sp);
- atomic_load(&sp);
- atomic_store(&sp, sp2);
- atomic_exchange(&sp, sp2);

```c++
std::shared_ptr<X> global;

void foo() {
    std::shared_ptr<X> local{new X};
    // use atomic operations in case of data race
    std::atomic_store(&global, local);
}
```

### Unique Pointer

1. 获得某些资源
2. 执行某些操作
3. 将取得的资源释放掉

```c++
void f() {
    ClassA* ptr = new ClassA;
    ...
    delete ptr; // or use try catch for any exception
}

#include <memory>
void b() {
    std::unique<ClassA> ptr(new ClassA); // will be cleaned up automatically
}

void c() {
    std::unique_ptr<std::string> up(new std::string("nico"));
    (*up)[0] = 'N';
    up->append("lai");
    std::cout << *up << std::endl;
}
```

unique_ptr 仅支持 move 构造函数

```c++
std::unique_ptr<X> up1(new X);

std::unique_ptr<X> up2(up1); // ERROR, not possible

std::unique_ptr<X> up3(std::move(up1)); // OK
std::unique_ptr<X> up4 = std::move(up1); // OK
```

check [uniqueptr](./smart-pointer/uniqueptr.cc)

```c++
namespace std {
    template <typename T, typename D = default_delete<T>>
    class unique_ptr{
        public:
            T& operator*() const;
            T* operator->() const noexcept;
    };
    // specialized for array
    template <typename T, typename D>
    class unique_ptr<T[], D> {
        public:
            T& operator[](size_t i) const;
    }
}
```

### auto_ptr

C++11 明确声明不再支持。

### 总结

- shared_ptr 用来共享拥有权
- unique_ptr 用来独占拥有权

## 数值的极值

整数常量定义于＜ climits ＞和＜ limits.h ＞，浮点常量定义于＜ cfloat ＞和＜ float.h ＞

### Class numeric_limits<>

```c++
namespace std {
    template <typename T>
    class numeric_limits {
        public:
            static constexpr bool is_specialized = false;
    }
}

// int
template<> class numeric_limits<int> {
    static constexpr bool is_specialized = true;
    static constexpr int min() noexcept {
        return -2147483648;
    }
    static constexpr int max() noexcept {
        return 2147483647;
    }
    static constexpr int digits = 31;
}
```

check [limits](numeric-limits/limits.cc)

## Type Trait & Type Utility

```c++
template <typename T>
void foo(const T& val) {
    if (std::is_pointer<T>::value) {
        std::cout << "foo() called for a pointer" << std::endl;
    } else {
        std::cout << "foo() called for a value" << std::endl;
    }
}
```

by using type trait

```c++
template <typename T>
void fool_impl(T val, true_type);

template <typename T>
void fool_impl(T val, false_type);

template <typename T>
void foo(T val) {
    foo_impl(val, std::is_integral<T>());
}
```

return a common type

```c++
template <typename T1, typename T2>
typename std::common_type<T1, T2>::type min(const T1& x, const T2& y);

template <typename T1, typename T2>
struct common_type<T1, T2> {
    typedef decltype(true ? declval<T1>(): declval<T2>()) type;
}
```

## support functions

### min max `<algorithm>`

```c++
namespace std {
    template <typename T, typename Compare>
    const T& min(const T& a, const T& b, Compare cmp);
    template <typename T, typename Compare>
    T min(initializer_list<T> initlist, Compare cmp);
}
```

### swap

```c++
template <typename T>
inline void swap(T& a, T& b) ... {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

// for array since c++ 11
template <typename T, size_t N>
void swap(T (&a)[N], T (&b)[N]) noexcept(noexcept(swap(*a, *b)));
```

### comparison operator

只需定义好＜和==操作符就可以使用它们。只要写上 using namespace std：：rel_ops，下面的四个比较操作符就自动获得了定义。

```c++
namespace rel_ops {
    template <typename T>
    inline bool operator!= (const T& x, const T& y) {
        return !(x == y);
    }
    template <typename T>
    inline bool operator> (const T& x, const T& y) {
        return y < x;
    }
    template <typename T>
    inline bool operator<= (const T& x, const T& y) {
        return !(y < x);
    }
    template <typename T>
    inline bool operator>= (const T& x, const T& y) {
        return !(x < y);
    }
}
```

## Class ratio 的编译器分数运算

C++标准库提供了一个接口允许你具体指定编译期分数（compile-time frac-tion），并允许对它们执行编译期运算。

check [ratio](ratio/ratio.cc)

## Clock & Timer

Chrono 程序库的设计，是希望能够处理“timer 和 clock 在不同系统中可能不同”的事实，同时也是为了强化时间精准度。

### Duration

```c++
std::chrono::duration<int> twentySeconds(20);
std::chrono::duration<double, std::ratio<60>> halfAMinute(0.5);
std::chrono::duration<long, std::ratio<1, 1000>> oneMillisecond(1);

// C++标准库提供很多类型定义，如
typedef duration<signed int-type >= 64 bits, nano> nanoSeconds;

std::chrono::seconds twentySeconds(20);

// 通过duration_cast进行隐式转换
std::chrono::seconds sec(55);
std::chrono::minutes m1 = sec; // ERROR
std::chrono::minutes m2 = std::chrono::duration_cast<std::chrono::minutes>(sec); // OK
```

### Clock & Timepoint

check [clock](chrono/clock.cpp)

## 头文件
