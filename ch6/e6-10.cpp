#include <iostream>

using namespace std;

void swap(int *p, int *q)
{
    int t;
    t = *p;
    *p = *q;
    *q = t;
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 3;
    cout << "a = " << a << "b = " << b << endl;
    swap(&a, &b);
    cout << "a = " << a << "b = " << b << endl;

    return 0;
}
