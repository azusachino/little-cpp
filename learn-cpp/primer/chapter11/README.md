# 关联容器

## 关联容器概述

### 定义关联容器

当定义一个 map 时，必须既指明关键字类型又指明值类型；而定义一个 set 时，只需指明关键字类型，因为 set 中没有值。每个关联容器都定义了一个默认构造函数，它创建一个指定类型的空容器。我们也可以将关联容器初始化为另一个同类型容器的拷贝，或是从一个值范围来初始化关联容器，只要这些值可以转化为容器所需类型就可以。

```c++
map<string, size_t> word_count; // 空容器
set<string> exclude = {"the", "bar"}; // 列表初始化
map<string, string> authors = {{"A", "author"}, {"B","beca"}}; // {key, value}
```

### 关键字类型的要求

对于有序容器——map、multimap、set 以及 multiset，关键字类型必须定义元素比较的方法。默认情况下，标准库使用关键字类型的`<`运算符来比较两个关键字。在集合类型中，关键字类型就是元素类型；在映射类型中，关键字类型是元素的第一部分的类型。

```c++
bool compareIsbn(const Sales_data &l, const Sales_data &r) {
    return l.isbn() < r.isbn();
}

multiset<Sales_data, decltype(compareIsbn)*> bookStore(compareIsbn);
```

在定义 multiset 时我们必须提供两个类型：关键字类型 Sales_data，以及比较操作类型——应该是一种函数指针类型，可以指向 compareIsbn。

### pair 类型

make_pair

## 关联容器操作

额外的类型别名：

- key_type
- mapped_type
- value_type set: `key_type`, map: `pair<const key_type, mapped_type>`

### 关联容器迭代器

当解引用一个关联容器迭代器时，我们会得到一个类型为容器的 value_type 的值的引用。

```c++
auto map_it = word_count.begin(); // *map_it是一个指向pair<const string, size_t>对象的引用
map_it->first;
map_it->second;
map_it->first ="new key"; // 错误操作，关键字是const // 如果支持修改的话，迭代器就失效了
++map_it->second; // 可以改变元素
```

### 添加元素

```c++
word_count.insert({word, 1});
word_count.insert(make_pair(word, 1));
word_count.insert(pair<string, size_t>(word, 1));
word_count.insert(map<string, size_t>::value_type(word, 1));
```

insert（或 emplace）返回的值依赖于容器类型和参数。对于不包含重复关键字的容器，添加单一元素的 insert 和 emplace 版本返回一个 pair，告诉我们插入操作是否成功。pair 的 first 成员是一个迭代器，指向具有给定关键字的元素；second 成员是一个 bool 值，指出元素是插入成功还是已经存在于容器中。如果关键字已在容器中，则 insert 什么事情也不做，且返回值中的 bool 部分为 false。

### 删除元素

通过关键字 erase

### map 的下标操作

at

### 访问元素

## 无序容器

无序容器在存储上组织为一组桶，每个桶保存零个或多个元素。无序容器使用一个哈希函数将元素映射到桶。为了访问一个元素，容器首先计算元素的哈希值，它指出应该搜索哪个桶。容器将具有一个特定哈希值的所有元素都保存在相同的桶中。如果容器允许重复关键字，所有具有相同关键字的元素也都会在同一个桶中。因此，无序容器的性能依赖于哈希函数的质量和桶的数量和大小。

可以直接定义关键字是内置类型（包括指针类型）、string 还是智能指针类型的无序容器。

## 小结

有序容器使用比较函数来比较关键字，从而将元素按顺序存储。默认情况下，比较操作是采用关键字类型的<运算符。无序容器使用关键字类型的==运算符和一个 hash<key_type>类型的对象来组织元素。

允许重复关键字的容器的名字中都包含 multi；而使用哈希技术的容器的名字都以 unordered 开头。例如，set 是一个有序集合，其中每个关键字只可以出现一次；unordered_multiset 则是一个无序的关键字集合，其中关键字可以出现多次。
