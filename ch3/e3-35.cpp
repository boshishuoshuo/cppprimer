#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto i: a) cout << i << " ";
    cout << endl;
    int *p = begin(a);
    while (p != end(a))
    {
        *p = 0;
        p++;
    }
    for (auto i: a) cout << i << " ";
    cout << endl;
    return 0;
}
