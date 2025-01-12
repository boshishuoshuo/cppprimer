#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

void addFamily(map<string, vector<pair<string, string>>> & families, const string & family)
{
    families[family];
}

void addChild(map<string, vector<pair<string, string>>> & families, const string &family, const string & child, const string & bday)
{
    families[family].push_back({child, bday});
}

int main(int argc, char const *argv[])
{
    map<string, vector<pair<string, string>>> families;
    addFamily(families, "Feng");
    addChild(families, "Feng", "Zoe", "2/16");
    addChild(families, "Feng", "Mia", "1/3");
    addFamily(families, "Lee");
    addChild(families, "Lee", "Kayla", "2/20");
    addChild(families, "Lee", "Eileen", "1/20");

    for (auto f: families)
    {
        cout << f.first << " family: ";
        for (auto c: f.second)
            cout << c.first << " " << "birthday: " << c.second << ", ";
        cout << endl;
    }
    return 0;
}
