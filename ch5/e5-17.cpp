#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};

    auto it1 = v1.cbegin();
    auto it2 = v2.cbegin();

    while (it1 != v1.cend() && it2 != v2.cend())
    {
        if (*it1 != *it2) break;
        ++it1;
        ++it2;
    }
    if (it1 == v1.cend())
    {
        cout << "v1 is the prefix of v2" << endl;
        return 0;
    }
    if (it2 == v2.cend())
    {
        cout << "v2 is the prefix of v1" << endl;
        return 0;
    }
    cout << "v1 and v2 are not prefix of each other" << endl;
    return 0;
}
