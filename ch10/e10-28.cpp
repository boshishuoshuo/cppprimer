#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void printVec(vector<int> & v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
        
    }
    cout << endl;
}

void printList(list<int> & v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
       
    }
     cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVec(v1);
    list<int> v2, v3, v4;
    copy(v1.begin(), v1.end(), inserter(v2, v2.begin()));
    printList(v2);
    copy(v1.begin(), v1.end(), back_inserter(v3));
    printList(v3);
    copy(v1.begin(), v1.end(), front_inserter(v4));
    printList(v4);
    return 0;
}
