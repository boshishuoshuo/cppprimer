#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    list<int> lst = { 1, 2, 3, 4, 5};
    copy(lst.begin(), lst.end(), back_inserter(vInt));
    cout << equal(lst.begin(), lst.end(), vInt.begin()) << endl;
    for (auto it = vInt.begin(); it != vInt.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
