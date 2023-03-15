#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void addFamily(map<string, vector<string>> & families, const string & family)
{
    if (families.find(family) == families.end())
        families[family] = vector<string>();
}

void addChild(map<string, vector<string>> & families, const string &family, const string & child)
{
    families[family].push_back(child);
}

int main(int argc, char const *argv[])
{
    map<string, vector<string>> families;
    addFamily(families, "Feng");
    addChild(families, "Feng", "Zoe");
    addChild(families, "Feng", "Mia");
    addFamily(families, "Lee");
    addChild(families, "Lee", "Kayla");
    addChild(families, "Lee", "Eileen");

    for (auto f: families)
    {
        cout << f.first << " family: ";
        for (auto c: f.second)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
