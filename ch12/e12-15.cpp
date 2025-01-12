#include <iostream>
#include <memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
    cout << "open connection ... " << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "close connection ... " << endl;
}

void f(destination &d)
{
    cout << "directly manage connect " << endl;
    connection c = connect(&d);

    //forget to call disconnect

    cout << endl;
}

void f1(destination &d)
{
    cout << "Use shared_ptr to manage connect" << endl;
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *c){disconnect(*c);});
}

int main(int argc, char const *argv[])
{
    destination d;
    f(d);
    f1(d);
    return 0;
}
