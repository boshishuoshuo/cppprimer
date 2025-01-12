#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

void addChild(multimap<string, string> & families, const string &family, const string & child)
{
    families.insert({family,child});
}

int main(int argc, char const *argv[])
{
    multimap<string, string> families;
    addChild(families, "Feng", "Zoe");
    addChild(families, "Feng", "Mia");
    addChild(families, "Lee", "Kayla");
    addChild(families, "Lee", "Eileen");

    for (auto f: families)
    {
        cout << f.first << " family: " << f.second << endl;
    }
    return 0;
}
