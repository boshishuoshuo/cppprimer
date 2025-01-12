#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt = {1, 1, 2, 3, 1};
    int some_val = 1;
    int org_size = vInt.size();
    auto vInt_Begin = vInt.begin();
    int midSize = org_size / 2, i = 0;
    while ( i < midSize)
    {   
        if (*vInt_Begin == some_val)
        {
            vInt_Begin = vInt.insert(vInt_Begin, 2 * some_val);
            ++vInt_Begin;
            ++vInt_Begin;
        }
        i++;
    }

    for (auto it = vInt.begin(); it != vInt.end(); ++it)
    {
        cout << *it << " " ;
    }
    cout << endl;
    return 0;
}
