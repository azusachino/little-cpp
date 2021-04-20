#include <iostream>
#include <string>
#include "window_mgr.h"

using namespace std;

class Screen {
    friend void WindowMgr::clear(ScreenIndex);

public:
    // 定义类型别名
    typedef string::size_type pos;

    // 等价于 using pos = string::size_type;
    Screen() = default; // 因为我们已经提供了一个构造函数，所以编译器将不会自动生成默认的构造函数。如果我们的类需要默认构造函数，必须显式地把它声明出来。
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const // 隐式内联
    {
        return contents[cursor];
    }

    inline char get(pos ht, pos wd) const; // 显式内联
    Screen &move(pos r, pos c);

    void some() const;

private:
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};