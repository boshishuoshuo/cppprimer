#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "2 3 3 1 5 5 7 9 9 4 0 0";
    istringstream iss(s);
    istream_iterator<string> is_it(iss), eos;
    vector<string> vStr(is_it, eos);
    sort(vStr.begin(), vStr.end());
    ostream_iterator<string> os_it(cout, " ");
    unique_copy(vStr.begin(), vStr.end(), os_it);
    cout << endl;
    return 0;
}
