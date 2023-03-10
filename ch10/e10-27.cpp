#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt = {1, 1, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8};
    list<int> listInt;
    unique_copy(vInt.begin(), vInt.end(), back_inserter(listInt));
    for (auto i: listInt)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
