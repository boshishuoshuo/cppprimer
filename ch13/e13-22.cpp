#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    private:
        int i;
        string *ps;
    public:
        HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
        HasPtr(const HasPtr &h): ps(new string(*h.ps)), i(h.i) {}
        HasPtr& operator=(const HasPtr&h)
        {
            auto newps = new string(*h.ps);
            delete ps;
            ps = new string(*h.ps);
            i = h.i;
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
        ~HasPtr() {delete ps;}
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
