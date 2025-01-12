#include <iostream>
#include <memory>
#include <string>

using namespace std;

class DebugDelete
{
    public:
        DebugDelete(ostream &s = cerr) : os(s) {}
        template <typename T> void operator()(T *p) const
        {
            os << "deleting unique_ptr" << endl;
            delete p;
        }
    private:
        ostream &os;
};

int main(int argc, char const *argv[])
{
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int;
    DebugDelete()(ip);
    unique_ptr<int, DebugDelete> i(new int, DebugDelete());
    unique_ptr<string, DebugDelete> sp(new string("hello world"), DebugDelete());
    delete i.release();
    delete sp.release();
    return 0;
}
