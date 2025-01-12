#include <iostream>

using namespace std;

int fact(int i)
{
    if (i == 0 || i == 1) return 1;
    int result = 1;
    for (int j = 1; j <= i; ++j)
    {
        result *= j;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    for (int m = 0; m <= 10; ++m)
    {
        cout << fact(m) << endl;
    }
    return 0;
}
