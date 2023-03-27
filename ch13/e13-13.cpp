#include <iostream>
#include <vector>

using namespace std;

struct X 
{
    X() { cout << "constructor" << endl;}
    X(const X &) {cout << "copy constructor" << endl;}
    X& operator=(const X &rhs)
    {
        cout << "copy assign =" << endl;
        return *this;
    }
    ~X() {cout << "destructor" << endl;}
};

void f1(X x) {}

void f2(X &x) {}

int main(int argc, char const *argv[])
{
    cout << "local variable:" << endl;
    X x;
    cout << "not ref" << endl;
    f1(x);
    cout << "ref" << endl;
    f2(x);
    cout << "dynamic " << endl;
    X *px = new X;
    cout << "add to container" << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << "release dynamic object" << endl;
    delete px;
    cout << "indirect assign" << endl;
    X y = x;
    y = x;
    
    return 0;
}
