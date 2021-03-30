#include <string>

using namespace std;

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(const StrVec &);
    StrVec &operator=(StrVec &&) noexcept;
    ~StrVec();

    void push_back(const string &);
    size_t size() const
    {
        return first_free - elements;
    }
    size_t capacity() const
    {
        return cap - elements;
    }
    string *begin() const
    {
        return elements;
    }
    string *end() const
    {
        return first_free;
    }

private:
    static allocator<string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
        {
            reallocate();
        }
    }
    pair<string *, string *> alloc_n_copy(const string *b, const string *e);
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newData = alloc_n_copy(s.begin(), s.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    return *this;
}

void StrVec::reallocate()
{
    auto newCap = size() ? 2 * size() : 1;
    auto newData = alloc.allocate(newCap);

    auto dest = newData;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = elements + newCap;
}

// 移动构造函数  noexcept（它通知标准库我们的构造函数不抛出任何异常）
StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}