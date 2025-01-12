#include <memory>
#include <utility>
#include <string>
#include <cstdlib>
#include <new>

using namespace std;

void *operator new(size_t size)
{
    if (void *mem = malloc(size))
        return mem;
    else   
        throw bad_alloc();
}

void operator delete(void *mem) noexcept
{
    free(mem);
}

class StrVec
{
    private:
        static allocator<string> alloc;
        void chk_n_alloc()
            { if (size() == capacity()) reallocate();}
        pair<string*, string*> alloc_n_copy(const string*, const string*);
        void free();
        void reallocate();
        void reallocate(size_t);
        string *elements;
        string *first_free;
        string *cap;

    public:
        StrVec(): elements(nullptr), first_free(nullptr),
            cap(nullptr) {}
        StrVec(initializer_list<string>);
        StrVec(const StrVec&);
        StrVec & operator=(const StrVec&);
        ~StrVec();
        void push_back(const string&);
        void reserve(size_t);
        void resize(size_t);
        void resize(size_t, const string &);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        string *begin() const { return elements; }
        string *end() const { return first_free; }
};

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    //auto data = alloc.allocate(e - b);
    auto data = static_cast<string *>(operator new[]((e-b) *sizeof(string)));
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p!= elements; )
            alloc.destroy(--p);
        //alloc.deallocate(elements, cap - elements);
        operator delete[](elements);
    }
}

StrVec::StrVec(initializer_list<string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec & StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    //auto newdata = alloc.allocate(newcapacity);
    auto newdata = static_cast<string *>(operator new[](newcapacity *sizeof(string)));
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reallocate(size_t newcapacity)
{
    //auto newdata = alloc.allocate(newcapacity);
    auto newdata = static_cast<string *>(operator new[](newcapacity *sizeof(string)));
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    if (n > capacity())
        reallocate(n);
}

void StrVec::resize(size_t n)
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

void StrVec::resize(size_t n, const string &s)
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

allocator<string> StrVec::alloc;

int main(int argc, char const *argv[])
{
    StrVec strvec;
    
    return 0;
}
