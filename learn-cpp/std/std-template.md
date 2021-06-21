# 标准模板库

## STL 组件

### 容器

1. Sequence Container => array, vector, deque, list, forward_list
2. Associative Container => set, multiset, map, multimap
3. Unordered (associative) Container => unordered_set, unordered_multiset, unordered_map, unordered_multimap

#### vector

Vector 将其元素置于一个 dynamic array 中管理。它允许随机访问，可以利用索引直接访问任何一个元素。在 array 尾部附加元素或移除元素都很快速，但是在 array 的中段或起始段安插元素就比较费时，因为安插点之后的所有元素都必须移动，以保持原本的相对次序。

#### deque

它是一个 dynamic array，可以向两端发展，因此不论在尾部或头部安插元素都十分迅速。在中间部分安插元素则比较费时，因为必须移动其他元素。

#### array

一个 array 对象是在某个固定大小的 array （有时称为一个 static array 或 Carray）内管理元素。因此，你不可以改变元素个数，只能改变元素值。你必须在建立时就指明其大小。Array 也允许随机访问，可以直接访问任何一个元素。

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

无序（unordered）容器常以 hash table 实现出来（如图 6.3 所示），内部结构是一个“由 linked list 组成”的 array。通过某个 hash 函数的运算，确定元素落于这个 array 的位置。Hash 函数运算的目标是：让每个元素的落点（位置）有助于用户快速访问任何一个元素。

#### 关联式数组

不论 map 或 unordered map，都是 key/value pair 形成的集合，每个元素带着独一无二的 key。如此的集合也可被视为一个关联式数组（associative array），也就是“索引并非整数”的 array。
