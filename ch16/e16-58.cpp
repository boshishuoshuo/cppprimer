#include <memory>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Vec
{
    private:
        static allocator<T> alloc;
    private:
        void chk_n_alloc()
            { if (size() == capacity()) reallocate();}
        pair<T*, T*> alloc_n_copy(const T*, const T*);
        void free();
        void reallocate();
        void reallocate(size_t);
        string *elements;
        string *first_free;
        string *cap;

    public:
        Vec(): elements(nullptr), first_free(nullptr),
            cap(nullptr) {}
        Vec(initializer_list<T>);
        Vec(const Vec&);
        Vec & operator=(const Vec&);
        ~Vec();
        void push_back(const T&);
        void reserve(size_t);
        void resize(size_t);
        void resize(size_t, const T&);
        template <class... Args> void emplace_back(Args&&...);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        string *begin() const { return elements; }
        string *end() const { return first_free; }
};

template <typename T>
void Vec<T>::push_back(const T &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
    if (elements)
    {
        for (auto p = first_free; p!= elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(initializer_list<T> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(const Vec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
Vec<T> & Vec<T>::operator=(const Vec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::reallocate(size_t newcapacity)
{
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
    if (n > capacity())
        reallocate(n);
}

template <typename T>
void Vec<T>::resize(size_t n)
{
    if (n > size())
    {
        while (size() < n)
            push_back("");
    } else if ( n < size())
    {
        while (size() > n)
            alloc.destroy(--first_free);
    }
}

template <typename T>
void Vec<T>::resize(size_t n, const T &s)
{
    if (n > size())
    {
        while (size() < n)
            push_back(s);
    } else if ( n < size())
    {
        while (size() > n)
            alloc.destroy(--first_free);
    }
}

template <typename T>
template <class... Args>
inline
void Vec<T>::emplace_back(Args&&... args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
allocator<T> Vec<T>::alloc;

int main(int argc, char const *argv[])
{
    Vec<string> strvec;
    strvec = {"hello", "world", "zoe", "mia"};
    cout << strvec.size() << endl;
    strvec.emplace_back(10, 'c');
    cout << strvec.size() << endl;
    for (auto it = strvec.begin(); it != strvec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    strvec.emplace_back("END");
    cout << strvec.size() << endl;
    for (auto it = strvec.begin(); it != strvec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
