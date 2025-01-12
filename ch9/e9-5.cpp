#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator lookingfor(vector<int>::iterator it1, vector<int>::iterator it2, int i)
{
    while (it1 != it2)
    {
        if (*it1 == i)
            return it1;
        ++it1;
    }
    return it2;
}

int main(int argc, char const *argv[])
{
    vector<int> vInt = {1, 3, 5, 7, 9};

    vector<int>::iterator is7 = lookingfor(vInt.begin(), vInt.end(), 7);
    if (is7 != vInt.end())
        cout << "7 can be found? " << *is7 << endl;
    else 
        cout << "7 can not be found " << endl;
    vector<int>::iterator is8 = lookingfor(vInt.begin(), vInt.end(), 8);
    if (is8 != vInt.end())
        cout << "8 can be found? " << *is8 << endl;
    else 
        cout << "8 can not be found " << endl;

    return 0;
}
