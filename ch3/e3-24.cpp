#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( (it+1) == v.end()) break;
        
        cout << *it + *(it + 1) << endl;
    }

    auto ib = v.begin();
    auto ie = v.end() - 1;

    while (ib <= ie)
    {
        if (ib == ie)
            cout << *ib << endl;
        else
        {
            cout << "ib: " << *ib << "ie: " << *ie << endl;
            cout << *ib + *ie << endl;
        }
        ib++;
        ie--;
    }

    
    return 0;
}