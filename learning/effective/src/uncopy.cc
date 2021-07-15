class UnCopyable
{
protected:
    UnCopyable() {}
    ~UnCopyable() {}

private:
    UnCopyable(const UnCopyable &);
    UnCopyable &operator=(const UnCopyable &);
};

// homeForSale will not be able to copy
class HomeForSale : private UnCopyable
{
};