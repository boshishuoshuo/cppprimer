#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    list<char *> slist = {"hello", "world", "!"};
    vector<string> svec;

    svec.assign(slist.begin(), slist.end());

    cout << svec.capacity() << " " << svec.size() << " "
        << svec[0] << " " << svec[svec.size() - 1] << endl;

    return 0;
}