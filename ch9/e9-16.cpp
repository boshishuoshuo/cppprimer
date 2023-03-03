#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool v_l_equal(vector<int> &v, list<int> &l)
{
    if (v.size() != l.size()) 
        return false;
    auto vb = v.begin();
    auto ve = v.end();
    auto lb = l.begin();

    for (; vb != ve; ++vb, ++lb)
    {
        if (*vb != *lb)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    list<int> ilist1 = {1, 2, 3, 4, 5};
    list<int> ilist2 = {1, 2, 3, 4, 5, 6, 8};
    list<int> ilist3 = {1, 2, 3, 4, 5, 7, 6};

    cout << v_l_equal(ivec, ilist) << endl;
    cout << v_l_equal(ivec, ilist1) << endl;
    cout << v_l_equal(ivec, ilist2) << endl;
    cout << v_l_equal(ivec, ilist3) << endl;

    return 0;
}
