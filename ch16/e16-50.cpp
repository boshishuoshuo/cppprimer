#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T> void f(T a)
{
    cout << "f(T), T is " << typeid(T).name() << endl;
}

template<typename T> void f(const T *a)
{
    cout << "f(const T *), const T* is " << typeid(const T*).name() << endl;
}

template<typename T> void g(T a)
{
    cout << "g(T), T is " << typeid(T).name() << endl;
}

template<typename T> void g(T *a)
{
    cout << "g(T*), T* is " << typeid(T*).name() << endl;
}

int main(int argc, char const *argv[])
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);
    return 0;
}
