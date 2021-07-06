# STL 特殊

## tuple

tuple 是类似 pair 的模板。每个 pair 的成员类型都不相同，但每个 pair 都恰好有两个成员。不同 tuple 类型的成员类型也不相同，但一个 tuple 可以有任意数量的成员。每个确定的 tuple 类型的成员数目是固定的，但一个 tuple 类型的成员数目可以与另一个 tuple 类型不同。

```c++
tuple<size_t, size_t, size_t> threeD;
tuple<string, vector<double>, int, list<int>> someVal("a", {3.12, 2.32}, 42, {0,1,2,3,4,5});
```

tuple 的构造函数是 explicit 的，必须使用直接初始化语法

```c++
// wrong
tuple<size_t, size_t> twoD = {1, 2};
tuple<size_t, size_t> twoD{1,2}; // ok

auto item = make_tuple("abc", 12, 1.23);
auto b = get<0>(item);

typedef decltype(item) trans;
size_t sz = tuple_size<trans>::value;
tuple_element<1, trans>::type cnt = get<1>(item);
```

## bitset

标准库定义了 bitset 类，使得位运算的使用更为容易，并且能够处理超过最长整型类型大小的位集合。bitset 类定义在头文件 bitset 中。

```c++
bitset<32> bitvec(1U);
bool is_set = bitvec.any();
bool is_not_set = bitvec.none();
bool all_set = bitvec.all();
size_t onBits = bitvec.count();
size_t sz = bitvec.size();
bitvec.flip();
bitvec.reset();
bitvec.set();
```

## 正则表达式 - regex

```c++
string pattern("[^c]ei");
regex r(pattern);
smatch results;
string test_str = "receipt friend theif receive";
if (regex_search(test_str, results, r)) {
    cout << results.str() << endl;
}
```

## 随机数 - rand

随机数引擎类（random-number engines）和随机数分布类（random-numberdistribution

```c++

uniform_int_distribution<unsigned> u(0,9);
default_random_engine e;
for (size_t i = 0; i < 10; i++) {
    cout << e() << " ";
    cout << u(e) << " ";
}


```

## IO 库再探

### 格式化输入输出

操纵符改变对象的格式状态的一个例子是 boolalpha 操纵符。默认情况下，bool 值打印为 1 或 0。一个 true 值输出为整数 1，而 false 输出为 0。

默认情况下，整型值的输入输出使用十进制。我们可以使用操纵符 hex、oct 和 dec 将其改为十六进制、八进制或是改回十进制

默认情况下，当一个浮点值的小数部分为 0 时，不显示小数点。showpoint 操纵符强制打印小数点

- setw 指定下一个数字或字符串值的最小空间。
- left 表示左对齐输出。
- right 表示右对齐输出，右对齐是默认格式。
- internal 控制负数的符号的位置，它左对齐符号，右对齐值，用空格填满所有中间空间。
- setfill 允许指定一个字符代替默认的空格来补白输出。

```c++
bool bool_val = get_status();
cout << boolalpha << bool_val << noboolalpha;
```
