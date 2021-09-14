# 标准模板库

## STL 组件

### 容器

1. Sequence Container => array, vector, deque, list, forward_list
2. Associative Container => set, multiset, map, multimap
3. Unordered (associative) Container => unordered_set, unordered_multiset, unordered_map, unordered_multimap

#### vector

Vector 将其元素置于一个 dynamic array 中管理。它允许随机访问，可以利用索引直接访问任何一个元素。在 array 尾部附加元素或移除元素都很快速，但是在 array
的中段或起始段安插元素就比较费时，因为安插点之后的所有元素都必须移动，以保持原本的相对次序。

#### deque

它是一个 dynamic array，可以向两端发展，因此不论在尾部或头部安插元素都十分迅速。在中间部分安插元素则比较费时，因为必须移动其他元素。

#### array

一个 array 对象是在某个固定大小的 array （有时称为一个 static array 或 Carray）内管理元素。因此，你不可以改变元素个数，只能改变元素值。你必须在建立时就指明其大小。Array
也允许随机访问，可以直接访问任何一个元素。

#### list

`list<>` 由双向链表（doubly linked list）实现而成。这意味着 list 内的每个元素都以一部分内存指示其前导元素和后继元素。

#### forward_list

C++标准库提供了另一个 list 容器：forward list。forward_list ＜＞是一个由元素构成的单向（singly） linked list。

#### 关联式容器

- Set 元素依据其 value 自动排序，每个元素只能出现一次，不允许重复。
- Multiset 和 set 的唯一差别是：元素可以重复。也就是 multiset 可包括多个“value 相同”的元素。
- Map 每个元素都是 key/value pair，其中 key 是排序准则的基准。每个 key 只能出现一次，不允许重复。Map 也可被视为一种关联式数组（associative array），也就是“索引可为任意类型”的数组。
- Multimap 和 map 的唯一差别是：元素可以重复，也就是 multimap 允许其元素拥有相同的 key。Multimap 可被当作字典（dictionary）使用。

#### 无序容器

无序（unordered）容器常以 hash table 实现出来（如图 6.3 所示），内部结构是一个“由 linked list 组成”的 array。通过某个 hash 函数的运算，确定元素落于这个 array 的位置。Hash
函数运算的目标是：让每个元素的落点（位置）有助于用户快速访问任何一个元素。

#### 关联式数组

不论 map 或 unordered map，都是 key/value pair 形成的集合，每个元素带着独一无二的 key。如此的集合也可被视为一个关联式数组（associative array），也就是“索引并非整数”的 array。

## 迭代器

迭代器是一个“可遍历 STL 容器全部或部分元素”的对象。迭代器用来表现容器中的某一个位置。基本操作如下：

- `Operator*` 返回当前位置上的元素值
- `Operator++`令迭代器前进至下一元素
- `Operator==, !=`判断两个迭代器是否指向同一位置
- `Operator=`对迭代器赋值

### 迭代器种类

- 前向迭代器只能够以累加操作符向前迭代
- 双向迭代器可以双向行进
- 随机访问迭代器，不带具备双向迭代器的所有属性，还具备随机访问能力。

## 算法

STL 提供了一些标准算法，包括查找、排序、拷贝、重新排序、修改、数值运算等基本而普遍的算法。

**如果某个算法用来处理多重区间，那么当你调用它时，务必确保第二（以及其他）区间所拥有的元素个数至少和第一区间内的元素个数相同。**

### 迭代器之适配器

- Insert Iterator
- Stream Iterator
- Reverse Iterator
- Move Iterator

#### insert

可以使算法以安插（insert）方式而非覆写（overwrite）方式运作。

#### stream

Stream iterator 被用来读/写 stream。

#### reverse

Reverse iterator 会造成算法逆向操作，其内部将对 increment（递增）操作符的调用转换为对 decrement（递减）操作符的调用

## User defined GenericFunction

STL
是一个可扩充框架。它的意思是你可以写你自己的函数和算法，用以处理集合内的元素。当然这些操作函数也可以是泛化的（generic）。然而，若要在这些操作函数内声明一个合法的迭代器，必须与容器类型相应，因为不同的容器有不同的迭代器。为了协助写出泛型函数，每一个容器类型都提供有若干内部的类型定义。

## Manipulating Algorithm

[remove](stl/remove1.cc)

## 以函数作为算法实参

[foreach](stl/foreach1.cc)

## Lambda

```c++
std::transform(col.begin(), col.end(), col.begin(), [](double b) {return d*d*d;});
```

## 函数对象

函数对象是泛型编程（generic programming）强大威力和纯粹抽象概念的又一个例证。只要其行为像函数，它就是个函数。

1. 函数对象是一种带状态的函数
2. 每个函数对象都有其自己的类型
3. 函数对象通常比普通函数速度快

## STL 内部错误和异常

```c++
// iterbug.cc
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2;
    // RUNTIME ERROR: beginning is behind the end of the range
    vector<int>::iterator pos = v1.begin();
    reverse(++pos, v1.end());

    for (int i = 1; i <= 9; ++i) {
        v1.push_back(i);
    }

    // RUNTIME ERROR: overwriting nonexisting elements
    copy(v1.cbegin(), v1.cend(), v2.begin());
}
```
