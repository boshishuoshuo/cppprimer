#include <iostream>

using namespace std;

void reset(int &i)
{
    i = 0;
}

int main(int argc, char const *argv[])
{
    int p = 255;
    cout << "p = " << p << endl;
    reset(p);
    cout << "p = " << p << endl;
    
    return 0;
}
