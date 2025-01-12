#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<pair<string, int>> vp;
    vp.push_back(pair<string, int>("Zoe", 8));
    vp.push_back(pair<string, int>("Mia", 6));
    for (auto v: vp)
    {
        cout << v.first << " age: " << v.second << endl;
    }
    return 0;
}
