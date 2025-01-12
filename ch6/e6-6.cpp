#include <iostream>

using namespace std;

int absolute(int value)
{
    if (value >= 0)
    {
        return value;
    } else{
        return -value;
    }
}

int main(int argc, char const *argv[])
{
    cout << absolute(10) << endl;
    cout << absolute(0) << endl;
    cout << absolute(-10) << endl;
    return 0;
}
