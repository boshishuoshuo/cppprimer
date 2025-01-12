#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    multimap<string, string> m;
    m.insert({"Feng", "work1"});
    m.insert({"Yan", "work1"});
    m.insert({"Feng", "work2"});
    m.insert({"Yan", "work2"});
    for (auto n: m)
    {
        cout << "author: "<< n.first << " work: " << n.second << endl;
    }
    auto p = m.find("Feng");
    if (p != m.end())
        m.erase(p);
    for (auto n: m)
    {
        cout << "author: "<< n.first << " work: " << n.second << endl;
    }
    return 0;
}
