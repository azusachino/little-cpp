#include <utility>

class Bitmap
{
};

class Widget
{

private:
    Bitmap *pb;
};

Widget &Widget::operator=(const Widget &rhs)
{
    // 如果rhs是this，widget将持有一个指针指向已删除对象
    delete pb;
    pb = new Bitmap(*rhs.pb); // call copy constructor
    return *this;
}

Widget &Widget::operator=(const Widget &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    // 如果new Bitmap()出现异常，widget将持有一个指针指向一块被删除的bitmap
    delete pb;
    pb = new Bitmap(*rhs.pb); // call copy constructor
    return *this;
}

Widget &Widget::operator=(const Widget &rhs)
{
    Bitmap *orig = pb;
    pb = new Bitmap(*rhs.pb);
    delete orig;
    return *this;
}

// Widget &Widget::operator=(const Widget &rhs)
// {
//     Widget temp(rhs);
//     swap(this, temp);
//     return *this;
// }

// Widget &Widget::operator=(Widget rhs)
// {
//     swap(rhs);
//     return *this;
// }
