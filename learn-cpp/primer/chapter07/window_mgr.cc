#include <vector>
#include "window_mgr.h"

using namespace std;

class WindowMgr {
public:
    using ScreenIndex = vector<Screen>::size_type;

    void clear(ScreenIndex);

    ScreenIndex addScreen(const Screen &);

private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

void WindowMgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    //  s.contents = string(s.height * s.width, ' ');
}

WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}