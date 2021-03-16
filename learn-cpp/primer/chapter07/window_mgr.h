#include <vector>
#include "screen.h"

class WindowMgr
{
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};