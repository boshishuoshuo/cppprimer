#include <iostream>

using namespace std;

namespace Exercise
{   
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
} // namespace Exercise

int ivar = 0;

using namespace Exercise;

int main(int argc, char const *argv[])
{
    double dvar = 3.1416;
    int iobj = limit + 1;
    //++ivar;
    //cout << "ivar: " << ivar << endl;
    ++::ivar;
    cout << "dvar: " << dvar << endl;
    cout << "iobj: " << iobj << endl;
    cout << "ivar: " << ::ivar << endl;
    cout << "limit: " << limit << endl;
    return 0;
}
