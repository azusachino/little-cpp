# CPP 面向对象

```c++
C++ 支持面向对象程序设计 类是 C++ 的核心特性 通常被称为用户定义的类型
类用于指定对象的形式 它包含了数据表示法和用于处理数据的方法

继承, 一个子类可以有多个父类 它继承了多个父类的特性
多继承(环形继承),A->D, B->D, C->(A, B)会使D创建两个对象, 解决办法-> 用虚拟继承格式
class D{......};
class B: virtual public D{......};
class A: virtual public D{......};
class C: public B, public A{.....};

重载方法, 重载运算符
// 重载 + 运算符 用于把两个 Box 对象相加
Box operator+(const Box& b)
{
  Box box;
  box.length = this->length + b.length;
  box.breadth = this->breadth + b.breadth;
  box.height = this->height + b.height;
  return box;
}
==> Box1 + Box2

可重载的运算符
双目算术运算符	+ (加), -(减), *(乘), /(除), % (取模)
关系运算符	==(等于), != (不等于), < (小于), > (大于>, <=(小于等于), >=(大于等于)
逻辑运算符	||(逻辑或), &&(逻辑与), !(逻辑非)
单目运算符	+ (正), -(负), *(指针), &(取地址)
自增自减运算符	++(自增), --(自减)
位运算符	| (按位或), & (按位与), ~(按位取反), ^(按位异或),, << (左移), >>(右移)
赋值运算符	=, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=
空间申请与释放	new, delete, new[ ] , delete[]
其他运算符	()(函数调用), ->(成员访问), ,(逗号), [](下标)

如果类中至少有一个函数被声明为纯虚函数 这个类就是抽象类 纯虚函数是通过在声明中使用 "= 0" 来指定的

```

class
```c++
#include <iostream>
 
using namespace std;
 
// 基类 Shape
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// 基类 PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};
 
// 派生类
class Rectangle: public Shape, public PaintCost
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};
 
int main(void)
{
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
 
   area = Rect.getArea();
   
   // 输出对象的面积
   cout << "Total area: " << Rect.getArea() << endl;
 
   // 输出总花费
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;
 
   return 0;
}

```

friend function

```c++
#include <iostream>
 
using namespace std;
//要访问非static成员时, 需要对象做参数；
//要访问static成员或全局变量时, 则不需要对象做参数；
//如果做参数的对象是全局对象, 则不需要对象做参数.

class Box
{
    double width;
public:
    friend void printWidth(Box box);
    friend class BigBox;
    void setWidth(double wid);
};

class BigBox
{
public :
    void Print(int width, Box &box)
    {
        // BigBox是Box的友元类, 它可以直接访问Box类的任何成员
        box.setWidth(width);
        cout << "Width of box : " << box.width << endl;
    }
};

// 成员函数定义
void Box::setWidth(double wid)
{
    width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
    /* 因为 printWidth() 是 Box 的友元, 它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width << endl;
}

// 程序的主函数
int main()
{
    Box box;
    BigBox big;

    // 使用成员函数设置宽度
    box.setWidth(10.0);

    // 使用友元函数输出宽度
    printWidth(box);

    // 使用友元类中的方法设置宽度
    big.Print(20, box);

    getchar();
    return 0;
}
```

inline function

```c++
内联函数inline引入内联函数的目的是为了解决程序中函数调用的效率问题 
程序在编译器编译的时候, 编译器将程序中出现的内联函数的调用表达式用内联函数的函数体进行替换, 而对于其他的函数, 都是在运行时候才被替代。
这其实就是个空间代价换时间的i节省 所以内联函数一般都是1-5行的小函数 在使用内联函数时要留神

1.在内联函数内不允许使用循环语句和开关语句
2.内联函数的定义必须出现在内联函数第一次调用之前
3.类结构中所在的类说明内部定义的函数是内联函数
#include <iostream>
 
using namespace std;

inline int Max(int x, int y)
{
   return (x > y)? x : y;
}

// 程序的主函数
int main( )
{

   cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;
   return 0;
}
```

ptr

```c++

#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      int compare(Box box)
      {
         return this->Volume() > box.Volume();
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};
 
int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2
 
   if(Box1.compare(Box2))
   {
      cout << "Box2 is smaller than Box1" <<endl;
   }
   else
   {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   return 0;
}
```

pure virtual function

```c++
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      // pure virtual function
      virtual int area() = 0; // 专门用于继承重载
};
```