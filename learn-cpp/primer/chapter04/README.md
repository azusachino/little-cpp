# C++Primer Chapter04

## Basic

- 一元运算符：作用于一个运算对象，解引用符`*`，取地址符`&`。
- 二元运算符：作用于两个运算对象，乘法运算符`*`，相等运算符`==`。

运算符的优先级、结合律以及运算对象的求值顺序。

### 重载运算符

C++语言定义了运算符作用于内置类型和复合类型的运算对象时所执行的操作。当运算符作用于类类型的运算对象时，用户可以自行定义其含义。IO库的>>和<<运算符以及string对象、vector对象和迭代器使用的运算符都是重载的运算符。

### 左值和右值

当一个对象被用作右值时，用的是对象的值（内容）；当一个对象被用作左值时，用的是对象的身份。

### 处理复合表达式

1. 拿不准的时候最好用括号来强制让表达式的组合关系符合程序逻辑的要求。
2. 如果改变了某个运算对象的值，在表达式的其他地方不要再使用这个运算对象。

## 算术运算符

算术表达式可能产生未定义的结果。（数学性质，计算机溢出）

运算符`%`俗称“取余”或“取模”运算符，负责计算两个整数相除所得的余数，参与取余运算的运算对象必须是整数类型

## 逻辑和关系运算符

关系运算符作用于算术类型或指针类型，逻辑运算符作用于任意能转换成布尔值的类型。逻辑运算符和关系运算符的返回值都是布尔类型。

## 赋值运算符

赋值运算符的左侧运算对象必须是一个可修改的左值。

## 递增和递减运算符

递增运算符（++）和递减运算符（--）为对象的加1和减1操作提供了一种简洁的书写形式。

前置版本的运算符首先将运算对象加1（或减1），然后将改变后的对象作为求值结果。后置版本也会将运算对象加1（或减1），但是求值结果是运算对象改变之前那个值的副本。

`除非必须，否则不用递增递减运算符的后置版本`

```c++
auto pbeg = v.begin();
// 输出元素直至遇到第一个负值为止
while(pbeg != v.end() && *pbeg>0) {
    cout << *pbeg++ << endl; // 输出当前值并将pbeg向前移动一个元素
}
```

## 成员访问运算符

点运算符获取类对象的一个成员；箭头运算符与点运算符有关，表达式ptr->mem等价于（*ptr）.mem。

```c++
string s1 = "a string", *p = &s1;
auto n = s1.size(); // string对象s1的size成员
n = (*p).size(); // p所指对象的size成员
n = p->size(); // 等价于(*p).size()
*p.size(); // 错误，p是一个指针，没有size成员
```

## 条件运算符

条件运算符（？ ：）允许我们把简单的if-else逻辑嵌入到单个表达式当中。

条件运算符的优先级非常低，因此当一条长表达式中嵌套了条件运算子表达式时，通常需要在它两端加上括号。

## 位运算符

位运算符作用于整数类型的运算对象，并把运算对象看成是二进制位的集合。

## sizeof运算符

sizeof运算符返回一条表达式或一个类型名字所占的字节数。sizeof运算符满足右结合律，其所得的值是一个size_t类型的常量表达式。

```c++
Sales_data data, *p;
sizeof(Sales_data); // 存储Sales_data类型的对象所占的空间大小
sizeof data; // data的类型的大小
sizeof p; // 指针所占的空间大小
sizeof *p; // p所指类型的空间大小
sizeof data.revenue; // Sales_data的revenue成员所对应类型的大小
sizeof Sales_data::revenue;
```

- 对char或者类型为char的表达式执行sizeof运算，结果得1。
- 对引用类型执行sizeof运算得到被引用对象所占空间的大小。
- 对指针执行sizeof运算得到指针本身所占空间的大小。
- 对解引用指针执行sizeof运算得到指针指向的对象所占空间的大小，指针不需有效。
- 对数组执行sizeof运算得到整个数组所占空间的大小，等价于对数组中所有的元素各执行一次sizeof运算并将所得结果求和。注意，sizeof运算不会把数组转换成指针来处理
- 对string对象或vector对象执行sizeof运算只返回该类型固定部分的大小，不会计算对象中的元素占用了多少空间。

## 逗号运算符

逗号运算符（comma operator）含有两个运算对象，按照从左向右的顺序依次求值。

## 类型转换

### 隐式转换

- 在大多数表达式中，比int类型小的整型值首先提升为较大的整数类型。
- 在条件中，非布尔值转换成布尔类型。
- 初始化过程中，初始值转换成变量的类型；在赋值语句中，右侧运算对象转换成左侧运算对象的类型。
- 如果算术运算或关系运算的运算对象有多种类型，需要转换成同一种类型。
- 函数调用时也会发生类型转换。

### 算术转换：把一种算术类型转换成另一种算术类型

整型提升（integral promotion）负责把小整数类型转换成较大的整数类型。

### 其他隐式转换

1. 数组转换成指针
2. 指针的转换：常量整数值0或nullptr可以转换成任意指针类型；指向任意非常量的指针能转换成void*；指向任意对象的指针能转换成const void*。
3. 转换成布尔类型
4. 转换成常量
5. 类类型定义的转换

### 显式转换

`cast-name<type>(expression)`

type是转换的目标类型而expression是要转换的值。如果type是引用类型，则结果是左值。cast-name是static_cast、dynamic_cast、const_cast和reinterpret_cast中的一种。

## 习题集

### 假设i是int类型、d是double类型，书写表达式i*=d使其执行整数类型的乘法而非浮点类型的乘法

任何具有明确定义的类型转换，只要不包括底层const，都可以使用static_cast。  
`i *= static_cast<int>(d);`

### sizeof运算符与其他运算符的优先级关系

`(a) sizeof x+y (b) sizeof p->mem[i] (c) sizeof a<b (d) sizeof f()`

(a)的含义是先求变量x所占空间的大小，然后与变量y的值相加；因为sizeof运算符的优先级高于加法运算符的优先级，所以如果想求表达式x+y所占的内存空间，应该改为sizeof(x + y)。  
(b)的含义是先定位到指针p所指的对象，然后求该对象中名为mem的数组成员第i个元素的尺寸。因为成员选择运算符的优先级高于sizeof的优先级，所以本例无须添加括号。  
(c)的含义是先求变量a在内存中所占空间的大小，再把求得的值与变量b的值比较。因为sizeof运算符的优先级高于关系运算符的优先级，所以如果想求表达式a`<`b所占的内存空间，应该改为sizeof(a `<` b)。  
(d)的含义是求函数f()返回值所占内存空间的大小，因为函数调用运算符的优先级高于sizeof的优先级，所以本例无须添加括号。

### sizeof

```c++
int x[10]; 
int *p = x;
cout << sizeof(x)/ sizeof(*x) << endl; // 10，即数组容量
cout << sizeof(p)/ sizeof(*p) << endl; // 1
sizeof(x); // 整个数组所占空间的大小
sizeof(*x); // 数组第一个元素所占空间的大小
```