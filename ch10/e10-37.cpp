#include <iostream>
#include <vector>
#include <list>
#include <iterator>
 
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ostream_iterator<int> osit(cout, " ");
    copy(v.begin(), v.end(), osit);
    cout << endl;

    list<int> lst;

    reverse_iterator<vector<int>::iterator> re(v.begin() + 2);
    reverse_iterator<vector<int>::iterator> rb(v.begin() + 7);
    copy(rb, re, osit);
    cout << endl;
    return 0;
}
