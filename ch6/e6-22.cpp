#include <iostream>

using namespace std;

void SwapPointer1(int *p, int *q)
{
    int *tmp = p;
    p = q;
    q = tmp;
}

void SwapPointer2(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void SwapPointer3(int *&p, int *&q)
{
    int *tmp = p;
    p = q;
    q = tmp;
}


int main(int argc, char const *argv[])
{
    int a = 5, b = 10;
    int *p = &a, *q = &b;
    cout << "before:" << endl;
    cout << "p is " << p << endl;
    cout << "q is " << q << endl;
    cout << "*p is " << *p << endl;
    cout << "*q is " << *q << endl;
    SwapPointer1(p, q);
    cout << "after:" << endl;
    cout << "p is " << p << endl;
    cout << "q is " << q << endl;
    cout << "*p is " << *p << endl;
    cout << "*q is " << *q << endl;

    a = 5, b = 10;
    p = &a, q = &b;
    cout << "before:" << endl;
    cout << "p is " << p << endl;
    cout << "q is " << q << endl;
    cout << "*p is " << *p << endl;
    cout << "*q is " << *q << endl;
    SwapPointer2(p, q);
    cout << "after:" << endl;
    cout << "p is " << p << endl;
    cout << "q is " << q << endl;
    cout << "*p is " << *p << endl;
    cout << "*q is " << *q << endl;

    a = 5, b = 10;
    p = &a, q = &b;
    cout << "before:" << endl;
    cout << "p is " << p << endl;
    cout << "q is " << q << endl;
    cout << "*p is " << *p << endl;
    cout << "*q is " << *q << endl;
    SwapPointer3(p, q);
    cout << "after:" << endl;
    cout << "p is " << p << endl;
    cout << "q is " << q << endl;
    cout << "*p is " << *p << endl;
    cout << "*q is " << *q << endl;
    
    return 0;
}
