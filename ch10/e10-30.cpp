#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "2 3 1 5 7 9 4 0";
    istringstream iss(s);
    istream_iterator<int> is_it(iss), eos;
    vector<int> vInt;
    while(is_it != eos)
        vInt.push_back(*is_it++);
    sort(vInt.begin(), vInt.end());
    ostream_iterator<int> os_it(cout, " ");
    copy(vInt.begin(), vInt.end(), os_it);
    return 0;
}
