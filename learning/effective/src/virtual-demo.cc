#include <string>

class Transaction
{
public:
    Transaction();
    virtual void logT() const = 0;
};

Transaction::Transaction()
{
    logT(); // call virtual logT in constructor
}

// base class的构造函数执行赵宇derived class构造函数
class BuyTransaction : public Transaction
{
public:
    virtual void logT() const;
};

class SellTransaction : public Transaction
{
public:
    virtual void logT() const;
};

class T
{
public:
    explicit T(const std::string &li);
    void logT(const std::string &li) const; // non-virtual
};

T::T(const std::string &li)
{
    logT(li);
}

// 令derived classes将必要的构造信息向上传递至base class构造函数
class BuyT : public T
{
public:
    BuyT(std::string &lhs) : T(createLs(lhs)) {}

private:
    static std::string createLs(std::string &lhs);
};