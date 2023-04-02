#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
    public:
        typedef vector<string>::size_type size_type;
        StrBlob();
        StrBlob(initializer_list<string> il);
        StrBlob(vector<string> *);
        size_type size() const {return data->size();}
        bool empty() const {return data->empty();}
        void push_back(const string &t) {data->push_back(t);}
        void pop_back();
        string& front();
        const string& front() const;
        string& back();
        const string& back() const;
        string& operator[](size_t n) {return (*data)[n];}
        const string & operator[](size_t n) const {return (*data)[n];}

        StrBlobPtr begin();
        StrBlobPtr begin() const;
        StrBlobPtr end();
        StrBlobPtr end() const;
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const;
};

inline StrBlob::StrBlob(vector<string> *p): data(p) {}

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): 
                data(make_shared<vector<string>>(il)) {}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data <= *rhs.data;
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data > *rhs.data;
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data >= *rhs.data;
}

inline void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

inline string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr
{
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
    public:
        StrBlobPtr(): curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        StrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        string & deref() const;
        StrBlobPtr& incr();
        StrBlobPtr& decr();
        string& operator[](size_t n) {return (*wptr.lock())[n];}
        const string& operator[](size_t n) const {return (*wptr.lock())[n];}

        StrBlobPtr& operator++();
        StrBlobPtr& operator--();

        StrBlobPtr operator++(int);
        StrBlobPtr operator--(int);

        StrBlobPtr operator+(int);
        StrBlobPtr operator-(int);

        string& operator*() const;
        string* operator->() const;

    private:
        shared_ptr<vector<string>> check(size_t, const string&) const;
        weak_ptr<vector<string>> wptr;
        size_t curr;
};

inline
shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

inline string& StrBlobPtr::deref() const
{
    auto p = check(curr, "derefernce past end");
    return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::decr()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

inline StrBlobPtr StrBlob::end() const
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

inline bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return eq(lhs, rhs);
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return !eq(lhs, rhs);
}

inline
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();
    if (l == r)
        if (!r)
            return false;
        else
            return (lhs.curr < rhs.curr);
    else
        return false;
}

bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr <= rhs.curr);
    else
        return false;
}

bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();
    if (l == r)
        if (!r)
            return false;
        else
            return (lhs.curr > rhs.curr);
    else
        return false;
}

bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr >= rhs.curr);
    else
        return false;
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "increment past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator+(int n)
{
    auto ret = *this;
    ret.curr += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(int n)
{
    auto ret = *this;
    ret.curr -= n;
    return ret;
}

string& StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

string* StrBlobPtr::operator->() const
{
    return &(this->operator*());
}

#endif