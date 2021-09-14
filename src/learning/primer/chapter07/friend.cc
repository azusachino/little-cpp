#include <iostream>
#include <string>

using namespace std;

// 本题的真正关键之处是程序的组织结构，我们必须首先定义Window_mgr类，其中声明clear函数，但是不能定义它；
// 接下来定义Screen类，并且在其中指明clear函数是其友元；最后定义clear函数。满足题意的程序如下所示：

class window_mgr {
public:
    void clear();
};

class screen {
    friend void window_mgr::clear();

private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    string contents;

public:
    screen() = default;

    screen(unsigned ht, unsigned wd, char c)
            : height(ht), width(wd), contents(ht * wd, c) {}
};

void window_mgr::clear() {
    screen my_screen(10, 20, 'X');
    cout << my_screen.contents << endl;
    my_screen.contents = "";
    cout << my_screen.contents << endl;
}

int main() {
    window_mgr w;
    w.clear();
    return 0;
}