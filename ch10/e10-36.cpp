#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> lst1 = {1, 2, 3, 4, 5, 6};
    auto p = find(lst1.crbegin(), lst1.crend(), 0);
    if (p == lst1.crend())
        cout << "there is no zero in the lst1" << endl;

    list<int> lst = {0, 1, 1, 1, 2, 9, 3, 8, 4, 7, 5, 5, 6, 3, 4};
    p = find(lst.crbegin(), lst.crend(), 0);
    if (p != lst.crend())
    {
        int n = 0;
        for (auto it = lst.begin(); it != p.base(); ++it, ++n) ;
        cout << "The postion is " << n << endl;
    }
    return 0;
}
