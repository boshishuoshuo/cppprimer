#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Pleaes 2 integers: " << endl;

    int i1, i2;
    cin >> i1 >> i2;
    if (i2 == 0) 
    {
        throw runtime_error("divider can not be 0.");
    }
    cout << "the division is " << i1 / i2 << endl;
    return 0;
}