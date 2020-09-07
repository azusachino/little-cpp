# 高级教程

## 文件和流

```c++
ofstream	该数据类型表示输出文件流 用于创建文件并向文件写入信息
ifstream	该数据类型表示输入文件流 用于从文件读取信息
fstream	该数据类型通常表示文件流 且同时具有 ofstream 和 ifstream 两种功能 这意味着它可以创建文件 向文件写入信息 从文件读取信息

void open(const char *filename, ios::openmode mode);
```

```c++
#include <fstream>
#include <iostream>
using namespace std;
 
//向文件内部写入数据，并将数据读出
void file_wr(void)
{
    char data[100];
    //向文件写入数据
    ofstream outfile;
    outfile.open("test.txt");
    cout << "Write to the file" << endl;
    cout << "Enter your name:" << endl;
    cin.getline(data, 100);
    outfile << data << endl;
    cout << "Enter your age:" << endl;
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();
    //从文件读取数据
    ifstream infile;
    infile.open("test.txt");
    cout << "Read from the file" << endl;
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    infile.close();
}


//将数据从一文件复制到另一文件中
void file_copy(void)
{
    char data[100];
    ifstream infile;
    ofstream outfile;
    infile.open("test.txt");
    outfile.open("test_1.txt");
    cout << "copy from test.txt to test_1.txt" << endl;
    while (!infile.eof())
    {
        infile >> data;
        cout << data << endl;
        outfile << data << endl;
    }
    infile.close();
    outfile.close();
}
```

## 异常处理

```c++
throw: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的。
catch: 在您想要处理问题的地方，通过异常处理程序捕获异常。catch 关键字用于捕获异常。
try: try 块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个 catch 块。
```

```c++
#include <iostream>
using namespace std;
 
double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}
 
int main ()
{
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
     z = division(x, y);
     cout << z << endl;
   }catch (const char* msg) {
     cerr << msg << endl;
   }
 
   return 0;
}
```

## 动态内存

```c++
栈：在函数内部声明的所有变量都将占用栈内存。
堆：这是程序中未使用的内存，在程序运行时可用于动态分配内存。

double* pvalue  = NULL; // 初始化为 null 的指针
pvalue  = new double;   // 为变量请求内存
delete pvalue; // 释放 pvalue 所指向的内存

int main( )
{
   Box* myBoxArray = new Box[4];
 
   delete [] myBoxArray; // 删除数组
   return 0;
}
```

## 命名空间

```c++

#include <iostream>
using namespace std;
 
// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}
int main ()
{
 
   // 调用第一个命名空间中的函数
   first_space::func();
   
   // 调用第二个命名空间中的函数
   second_space::func(); 
 
   return 0;
}
```

## c++模板

```c++
模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。
typename && class 
模板是创建泛型类或函数的蓝图或公式。库容器，比如迭代器和算法，都是泛型编程的例子，它们都使用了模板的概念。

#include <iostream>
#include <string>
 
using namespace std;
 
template <typename T>
inline T const& Max (T const& a, T const& b) 
{ 
    return a < b ? b:a; 
} 
int main ()
{
 
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl; 
 
    double f1 = 13.5; 
    double f2 = 20.7; 
    cout << "Max(f1, f2): " << Max(f1, f2) << endl; 
 
    string s1 = "Hello"; 
    string s2 = "World"; 
    cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
 
   return 0;
}

---

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
 
using namespace std;
 
template <class T>
class Stack { 
  private: 
    vector<T> elems;     // 元素 
 
  public: 
    void push(T const&);  // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const{       // 如果为空则返回真。
        return elems.empty(); 
    } 
}; 
 
template <class T>
void Stack<T>::push (T const& elem) 
{ 
    // 追加传入元素的副本
    elems.push_back(elem);    
} 
 
template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    // 删除最后一个元素
    elems.pop_back();         
} 
 
template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    // 返回最后一个元素的副本 
    return elems.back();      
} 
 
int main() 
{ 
    try { 
        Stack<int>         intStack;  // int 类型的栈 
        Stack<string> stringStack;    // string 类型的栈 
 
        // 操作 int 类型的栈 
        intStack.push(7); 
        cout << intStack.top() <<endl; 
 
        // 操作 string 类型的栈 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}
```