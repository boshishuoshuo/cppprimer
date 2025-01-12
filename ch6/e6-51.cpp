#include <iostream>

using namespace std;

void f()
{
    cout << "No parameter" << endl;
}

void f(int, int)
{
    cout << "2 int parameters" << endl;
}

void f(int)
{
    cout << "1 int parameter" << endl;
}

void f(double a, double b = 3.14)
{
    cout << "2 double parameters" << endl;
}

int main(int argc, char const *argv[])
{
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
