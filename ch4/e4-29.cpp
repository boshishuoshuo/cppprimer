#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x[10];
    int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
    cout << sizeof(*p) << endl;
    cout << sizeof(p) << endl;
    return 0;
}
