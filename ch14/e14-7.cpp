#include <cstring>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iostream>
#include <memory>

using namespace std;

class String 
{
    friend String operator+(const String&, const String&);
    friend String add(const String&, const String&);
    friend std::ostream &operator<<(std::ostream&, const String&);
    friend std::ostream &print(std::ostream&, const String&);

    public:
	    String(): sz(0), p(0) { }

        // cp points to a null terminated array, 
        // allocate new memory & copy the array
	    String(const char *cp) : 
	          sz(std::strlen(cp)), p(a.allocate(sz))
	          { std::uninitialized_copy(cp, cp + sz, p); }

        // copy constructor: allocate a new copy of the characters in s
        String(const String &s):sz(s.sz), p(a.allocate(s.sz))
                { std::uninitialized_copy(s.p, s.p + sz , p); }

        String(size_t n, char c) : sz(n), p(a.allocate(n))
                { std::uninitialized_fill_n(p, sz, c); }

        // allocates a new copy of the data in the right-hand operand; 
        // deletes the memory used by the left-hand operand
        String &operator=(const String &);

        // unconditionally delete the memory because each String has its own memory
        ~String() { if (p) a.deallocate(p, sz); }
    public:
        // additional assignment operators
        String &operator=(const char*);         // car = "Studebaker"
        String &operator=(char);                // model = 'T'
        
        const char *begin()                         { return p; }
        const char *begin() const                   { return p; }
        const char *end()                      { return p + sz; }
        const char *end() const                { return p + sz; }

        size_t size() const                        { return sz; }
        void swap(String &s)
                        { char *tmp = p; p = s.p; s.p = tmp; 
                        std::size_t cnt = sz; sz = s.sz; s.sz = cnt; }
    private:
        std::size_t sz;
        char *p ;
        static std::allocator<char> a;
};

String make_plural(size_t ctr, const String &, const String &);
inline
void swap(String &s1, String &s2)
{
	s1.swap(s2);
}

// define the static allocator member
std::allocator<char> String::a;

// copy-assignment operator
String & String::operator=(const String &rhs)
{
	// copying the right-hand operand before deleting the left handles self-assignment
    char *newp = a.allocate(rhs.sz); // copy the underlying string from rhs
	uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);

	if (p)
		a.deallocate(p, sz); // free the memory used by the left-hand operand
	p = newp;    // p now points to the newly allocated string
	sz = rhs.sz; // update the size

    return *this;     
}

String& String::operator=(const char *cp)
{
	if (p) a.deallocate(p, sz);
	p = a.allocate(sz = strlen(cp));
	uninitialized_copy(cp, cp + sz, p);
	return *this;
}

String& String::operator=(char c)
{
	if(p) a.deallocate(p, sz);
	p = a.allocate(sz = 1);
	*p = c;
	return *this;
}

// named functions for operators
ostream &print(ostream &os, const String &s)
{
	const char *p = s.begin();
	while (p != s.end())
		os << *p++ ;
	return os;
}

String add(const String &lhs, const String &rhs) 
{
	String ret;
	ret.sz = rhs.size() + lhs.size();   // size of the combined String
	ret.p = String::a.allocate(ret.sz); // allocate new space
	uninitialized_copy(lhs.begin(), lhs.end(), ret.p); // copy the operands
	uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
	return ret;  // return a copy of the newly created String
}
	
// return plural version of word if ctr isn't 1
String make_plural(size_t ctr, const String &word,
                               const String &ending)
{
        return (ctr != 1) ?  add(word, ending) : word;
}

// chapter 14 will explain overloaded operators
ostream &operator<<(ostream &os, const String &s)
{
	return print(os, s);
}

String operator+(const String &lhs, const String &rhs) 
{
	return add(lhs, rhs);
}

