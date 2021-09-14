#include <string>

using namespace std;

typedef string Type;       // 声明类型别名Type表示string
Type initVal();  // 声明函数，返回类型是Type

class Exercise {
public:
    typedef double Type;  // 在内层作用域重新声明类型别名Type表示double
    Type setVal(Type);

    Type initVal();

private:
    int val;
};

Exercise::Type Exercise::setVal(Type p) {
    val = p + initVal();
    return val;
}

// 返回类型的Type为外层的string
// 入参的Type是Exercise作用域下的Type
// initVal也是Exercise作用于下的initVal
// Type Exercise::setVal(Type param){
//     val = param + initVal();
//     return val;
// }