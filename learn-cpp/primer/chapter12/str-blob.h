#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

// 提前声明：StrBlob中的友元声明需要
class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;

    StrBlob() = default;

    StrBlob(initializer_list<string> il);

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const string &t) {
        data->push_back(t);
    }

    void pop_back();

    string &front();

    const string &front() const;

    string &back();

    const string &back() const;

    // for StrBlobPtr
    StrBlobPtr begin();

    StrBlobPtr end();

private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {};

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr {
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr() : curr(0) {}

    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    string &deref() const;

    StrBlobPtr &incr();

    StrBlobPtr &decr();

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;

    weak_ptr<vector<string>> wptr;
    size_t curr;
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw runtime_error("unbound StrBlogPtr");
    }
    if (i >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

inline string &StrBlobPtr::deref() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}

inline StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end o StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::decr() {
    --curr;
    check(-1, "decrement past end o StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

inline bool eq(const StrBlobPtr &l, const StrBlobPtr &r) {
    auto lL = l.wptr.lock(), rL = r.wptr.lock();
    if (lL == rL) {
        return (!rL || l.curr == r.curr);
    } else {
        return false;
    }
}

inline bool neq(const StrBlobPtr &l, const StrBlobPtr &r) {
    return !eq(l, r);
}

#endif