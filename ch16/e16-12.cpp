#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> 
    bool operator==(const Blob<T> &, const Blob<T>&);

template <typename T> class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>
        (const Blob<T>&, const Blob<T>&);
    public:
        typedef T value_type;
        typedef typename vector<T>::size_type size_type;
        Blob();
        Blob(initializer_list<T> il);
        Blob(vector<T> *);
        size_type size() const {return data->size();}
        bool empty() const {return data->empty();}
        void push_back(const T &t) {data->push_back(t);}
        void push_back(const T &&t) {data->push_back(std::move(t));}
        void pop_back();
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;
        T& operator[](size_type i);

        BlobPtr<T> begin();
        BlobPtr<T> cbegin() const;
        BlobPtr<T> end();
        BlobPtr<T> cend() const;
    private:
        shared_ptr<vector<T>> data;
        void check(size_type i, const string &msg) const;
};

template <typename T> 
inline Blob<T>::Blob(vector<T> *p): data(p) {}

template <typename T>
inline Blob<T>::Blob(): data(make_shared<vector<T>>()) {}

template <typename T>
Blob<T>::Blob(initializer_list<T> il): 
                data(make_shared<vector<T>>(il)) {}

template <typename T>
inline void Blob<T>::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

template <typename T>
inline T& Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
inline const T& Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
inline T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
inline const T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
inline void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
bool eq(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr
{
    friend bool eq<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    public:
        BlobPtr(): curr(0) {}
        BlobPtr(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        BlobPtr(const Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        T& deref() const;
        T& operator*() const;
        BlobPtr& operator++();
        BlobPtr& operator++(int);
        BlobPtr& operator--();
        BlobPtr& operator--(int);
        BlobPtr& incr();
        BlobPtr& decr();
    private:
        shared_ptr<vector<T>> check(size_t, const string&) const;
        weak_ptr<vector<T>> wptr;
        size_t curr;
};

template <typename T>
inline shared_ptr<vector<T>>
BlobPtr<T>::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

template <typename T>
inline T& BlobPtr<T>::deref() const
{
    auto p = check(curr, "derefernce past end");
    return (*p)[curr];
}

template <typename T>
T& BlobPtr<T>::operator*() const
{
    auto p = check(curr, "derefernce past end");
    return (*p)[curr];
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::decr()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T>
inline BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template <typename T>
inline BlobPtr<T> Blob<T>::cbegin() const
{
    return BlobPtr<T>(*this);
}

template <typename T>
inline BlobPtr<T> Blob<T>::end()
{
    auto ret = BlobPtr<T>(*this, data->size());
    return ret;
}

template <typename T>
inline BlobPtr<T> Blob<T>::cend() const
{
    auto ret = BlobPtr<T>(*this, data->size());
    return ret;
}

template <typename T>
inline bool eq(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    auto l = lhs.wptr.lock();
    auto r = lhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

template <typename T>
inline
bool neq(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !eq(lhs, rhs);
}

int main(int argc, char const *argv[])
{
    Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (size_t i = 0; i != squares.size() ; ++i)
        squares[i] = i * i ;
    for (size_t i = 0; i != squares.size() ; ++i)
        cout << squares[i] << " ";
    cout << endl;
    return 0;
}
