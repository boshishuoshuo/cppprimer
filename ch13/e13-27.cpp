#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    private:
        size_t *use;
        int i;
        string *ps;
    public:
        HasPtr(const string &s = string()): ps(new string(s)), i(0), use(new size_t(0)) {}
        HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) { ++*use;}
        HasPtr& operator=(const HasPtr&rhs)
        {
            ++*rhs.use;
            if (--*use == 0)
            {
                delete ps;
                delete use;
            }
            ps = rhs.ps;
            use = rhs.use;
            i = rhs.i;
            return *this;
        }
        HasPtr& operator=(const string &s)
        {
            *ps = s;
            return *this;
        }
        string & operator*()
        {
            return *ps;
        }

        ~HasPtr() 
        {
            if (--*use == 0)
            {
                delete ps;
                delete use;
            }
        }
};

int main(int argc, char const *argv[])
{
    HasPtr h("hello world");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = "hi Zoe";
    h3 = "hi Mia";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    return 0;
}
