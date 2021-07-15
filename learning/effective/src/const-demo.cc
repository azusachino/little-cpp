#include <string>
#include <iostream>

class TextBlock
{
public:
    TextBlock(const std::string &s) : text(s) {}
    const char &operator[](std::size_t pos) const
    {
        return text[pos];
    }

    char &operator[](std::size_t pos)
    {
        return text[pos];
    }

private:
    std::string text;
};

void doSomething()
{
    TextBlock tb("Hello");
    std::cout << tb[0]; // call non-const

    const TextBlock ctb("World");
    std::cout << ctb[0]; // call const
}