#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char const *argv[])
{
    int i1, i2;
    while (true)
    {
        try {
            cout << "Pleaes 2 integers: " << endl;
            cin >> i1 >> i2;
            if (i2 == 0) 
            {
                throw runtime_error("divider can not be 0.");
            }
            cout << "the division is " << i1 / i2 << endl;
        } catch(runtime_error err)
        {
            cout << "error is " << err.what() << endl;
        }
        char c;
        cout << "Continue?" << endl;
        cin >> c;
        if (c == 'y' || c == 'Y')
            continue;
        else
            break;
    }
    return 0;
}