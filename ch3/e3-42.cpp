#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    const unsigned sz = 10;
    srand( (unsigned) time(NULL));
    for (size_t i = 0; i < 10; i++)
    {
        vInt.push_back(rand() % 10);
    }
    int a[sz];
    for (int j = 0; j < sz; j ++)
    {
        a[j] = vInt[j];
        cout << a[j] << " ";
    }
    cout << endl;
    return 0;
}