#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
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
        bool operator<(const HasPtr&) const;
        ~HasPtr() {delete ps;}
};

bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    cout << "swap " << *lhs.ps << " and " << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(int argc, char const *argv[])
{
    vector<HasPtr> vh;
    int n = 17;
    for (int i = n; i>=0; i--)
    {
        vh.push_back(to_string(i));
    }

    for (auto p : vh)
    {
        cout << *p << " ";
    }
    cout << endl;

    sort(vh.begin(), vh.end());
    for(auto p: vh)
    {
        cout << *p << " ";
    }
    cout << endl;
    return 0;
}
