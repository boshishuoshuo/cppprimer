#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Pleaes 2 integers: " << endl;

    int i1, i2;
    cin >> i1 >> i2;
    if (i2 == 0) 
    {
        cout << "divider can not be zero!" << endl;
        return -1;
    }
    cout << "the division is " << i1 / i2 << endl;
    return 0;
}
