# STL 容器成员

array, vector, deque, list, forward list, set, multiset, map, multimap, unordered set, unordered multiset, unordered map, ordered multimap, string

## 容器内的类型

container::xxx

- ::value_type
- ::reference
- ::const_reference
- ::iterator
- ::const_iterator
- ::reverse_iterator
- ::const_reverse_iterator
- ::pointer
- ::const_pointer
- ::size_type
- ::difference_type
- ::key_type
- ::mapped_type
- ::key_compare
- ::value_compare
- ::hasher
- ::key_equal
- ::local_iterator
- ::const_local_iterator

## 创建、复制和销毁

- ::container()
- ::container(size_type bnum)
- ::container(size_type bnum, const Hasher& hasher)
- ::container(size_type bnum, const Hasher& hasher, const KeyEqual& eqPred)
- ::container(initializer_list)
- ::container(initializer_list, const CompFunc& comPred)
- ::container(initializer_list, size_type bnum)
- ::container(initializer_list, size_type bnum, const Hasher& hasher)
- ::container(initializer_list, size_type bnum, const Hasher& hasher, const KeyEqual& eqPred)
- ::container(const container& c)
- ::container(const container&& c)
- expliciit container::container(size_type num)
- ::container(size_type num, const T& value)
- ::container(InputIterator beg, InputIterator end)
- ::container(InputIterator beg, InputIterator end, const CmpFunc & cmpPred)
- ::container(InputIterator beg, InputIterator end, size_type bnum)
- ::container(InputIterator beg, InputIterator end, size_type bnum, const Hasher& hasher)
- ::container(InputIterator beg, InputIterator end, size_type bnum, const Hasher& hasher, const KeyEqual& eqPred)
- ::~container()

## Nonmodifying Operation

### Size Operator

- bool ::empty() const
- size_type ::size() const
- size_type ::max_size() const

### Comparison Operation

- bool operator=(const container& c1, const container& c2)
- bool operator!=(const container& c1, const container& c2)
- bool operator<(const container& c1, const container& c2)
- bool operator<=(const container& c1, const container& c2)
- bool operator>(const container& c1, const container& c2)
- bool operator>=(const container& c1, const container& c2)

### Associative & Unorder

- size_type ::count(const T& value) const
- iterator ::find(const T& value)
- const_iterator ::find(const T& value)
- iterator ::lower_bound(const T& val)
- const iterator ::lower_bound(const T& val)
- iterator ::upper_bound(const T& val)
- const iterator ::upper_bound(const T& val)
- pair<iterator, iterator> ::equal_range(const T& val) == `make_pair(lower_bound(val), upper_bound(val))`
- pair<const_iterator, const_iterator> ::equal_range(const T& val)
