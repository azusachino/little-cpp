# C++Primer Chapter05

## 简单语句

C++语言中的大多数语句都以分号结束，一个表达式，比如ival + 5，末尾加上分号就变成了表达式语句（expression statement）。表达式语句的作用是执行表达式并丢弃掉求值结果。

### 空语句

最简单的语句是空语句（null statement），空语句中只含有一个单独的分号：`;`。（相当于python中的pass）

## 语句作用域

可以在if、switch、while和for语句的控制结构内定义变量。定义在控制结构当中的变量只在相应语句的内部可见，一旦语句结束，变量也就超出其作用范围了

## 条件语句

### if

if语句（if statement）的作用是：判断一个指定的条件是否为真，根据判断结果决定是否执行另外一条语句。

### switch

switch语句（switch statement）提供了一条便利的途径使得我们能够在若干固定选项中做出选择。

## 迭代语句

### while

只要条件为真，while语句（while statement）就重复地执行循环体

### for

```cc
for (init-statement;condition;expression)
    statement;
```

### do while

do while语句（do while statement）和while语句非常相似，唯一的区别是，dowhile语句先执行循环体后检查条件。不管条件的值如何，我们都至少执行一次循环。

## 跳转语句

跳转语句中断当前的执行过程。

### break

break语句（break statement）负责终止离它最近的while、do while、for或switch语句，并从这些语句之后的第一条语句开始继续执行。

### continue

continue语句（continue statement）终止最近的循环中的当前迭代并立即开始下一次迭代。continue语句只能出现在for、while和do while循环的内部，或者嵌套在此类循环里的语句或块的内部。和break语句类似的是，出现在嵌套循环中的continue语句也仅作用于离它最近的循环。和break语句不同的是，只有当switch语句嵌套在迭代语句内部时，才能在switch里使用continue。

### goto

goto语句（goto statement）的作用是从goto语句无条件跳转到同一函数内的另一条语句。

## try语句和异常处理

异常处理包括：

- throw表达式（throw expression），异常检测部分使用throw表达式来表示它遇到了无法处理的问题。我们说throw引发（raise）了异常。
- try语句块（try block），异常处理部分使用try语句块处理异常。try语句块以关键字try开始，并以一个或多个catch子句（catch clause）结束。try语句块中代码抛出的异常通常会被某个catch子句处理。因为catch子句“处理”异常，所以它们也被称作异常处理代码（exception handler）。
- 一套异常类（exception class），用于在throw表达式和相关的catch子句之间传递异常的具体信息。
