#include <iostream>
#include <string>

#include "window_mgr.h"

using namespace std;

class Screen {
public:
    // 定义类型别名
    typedef string::size_type pos;

    // 等价于 using pos = string::size_type;
    Screen() =
        default;  // 因为我们已经提供了一个构造函数，所以编译器将不会自动生成默认的构造函数。如果我们的类需要默认构造函数，必须显式地把它声明出来。
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const  // 隐式内联
    {
        return contents[cursor];
    }

    inline char get(pos ht, pos wd) const;  // 显式内联
    Screen &    move(pos r, pos c);

    void some() const;

    Screen &set(char);

    Screen &set(pos, pos, char);

    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    mutable size_t access_ctr;
    pos            cursor = 0;
    pos            height = 0, width = 0;
    string         contents;

    void do_display(ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor  = row + c;
    return *this;  // 以左值形式返回对象
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

void Screen::some() const {
    ++access_ctr;  // 保存一个计数器，用于记录成员函数被调用的次数
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}