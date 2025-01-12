#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    const unsigned sz = 10;
    int a[sz];
    srand( (unsigned) time(NULL));
    for (auto &e: a)
    {
        e = rand()%10;
        cout << e << endl;
    }
    vector<int> vInt(begin(a), end(a));
    for (auto e: vInt)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
