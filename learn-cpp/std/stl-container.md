# STL 容器

## 容器的共通能力和共通操作

### 共通能力

1. 所有容器提供的都是“value 语义”而非“reference 语义”。
2. 元素在容器内有其特定顺序。
3. 一般而言，各项操作并非绝对安全，也就是说它们并不会检查每一个可能发生的错误。

### 共通操作

1. 初始化: default, copy, ~(), initializer list
2. assignment & swap
3. empty(), size(), max_size()
4. comparison

size_type, difference_type, value_type, reference, const_reference, iterator, const_iterator, pointer, const_pointer

## Array

指一系列元素，有着固定大小。

和其他容器不同，不能对 array 的初值列（initializer list）使用小括号语法 `std::array<int, 5> a({1,2,3,4,5}); //ERROR`

## Vector

a dynamic array.

use `reserve()` to gurantee capacity.

## deque

double edge dynamic array.

## list

double linked list

## forward list

singly linked list
