#include <iostream>
#include <vector>

using namespace std;

bool lookingfor(vector<int>::iterator it1, vector<int>::iterator it2, int i)
{
    while (it1 != it2)
    {
        if (*it1 == i)
            return true;
        ++it1;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> vInt = {1, 3, 5, 7, 9};

    bool is7 = lookingfor(vInt.begin(), vInt.end(), 7);
    cout << "7 can be found? " << is7 << endl;
    bool is8 = lookingfor(vInt.begin(), vInt.end(), 8);
    cout << "8 can be found? " << is8 << endl;

    return 0;
}
