#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = vInt.end() - 1;
    while (it >= vInt.begin())
    {
        cout << *it << " ";
        it--;
    }

    cout << endl;

    for (auto iter = vInt.cend(); iter != vInt.begin();)
        cout << *(--iter) << " ";

    cout << endl;
    return 0;
}
