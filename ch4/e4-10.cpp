#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    while (cin >> num && num != 42)
    {
        cout << num << endl;
    }
    return 0;
}
