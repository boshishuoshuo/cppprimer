#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto it = vInt.begin(); it != vInt.end(); ++it)
        cout << *it << " ";
    cout << endl;

    fill_n(vInt.begin(), vInt.size(), 0);

    for (auto it = vInt.begin(); it != vInt.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
