#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    srand((unsigned) time(NULL));
    const int sz = 10;
    for (int i = 0; i != sz; ++i)
    {
        vInt.push_back(rand()%10);
        cout << vInt[i] << " ";
    }
    cout << endl;
    for (int j = 0; j != sz; ++j)
    {
        vInt[j] = (vInt[j] % 2 == 0) ? vInt[j] : 2 * vInt[j];
        cout << vInt[j] << " ";
    }
    cout << endl;
    return 0;
}
