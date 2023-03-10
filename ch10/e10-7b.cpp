#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    vInt.resize(10);
    for (auto it = vInt.begin(); it != vInt.end(); ++it)
        cout << *it << " ";
    cout << endl;
    fill_n(vInt.begin(), 10, 2);

    for (auto it = vInt.begin(); it != vInt.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
