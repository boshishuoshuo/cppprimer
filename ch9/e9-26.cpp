#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vInt;
    list<int> lInt;

    vInt.assign(ia, ia+11);
    lInt.assign(ia, ia+11);

    auto vInt_it = vInt.begin();
    while (vInt_it != vInt.end())
        if (*vInt_it & 1)
            ++vInt_it;
        else   
            vInt_it = vInt.erase(vInt_it);
    
    auto lInt_it = lInt.begin();
    while (lInt_it != lInt.end())
        if (*lInt_it & 1)
            lInt_it = lInt.erase(lInt_it);
        else
            ++lInt_it;

    for (auto it = vInt.begin(); it !=vInt.end(); ++it)
        cout << *it << " ";
    cout << endl;

    for (auto it = lInt.begin(); it !=lInt.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
