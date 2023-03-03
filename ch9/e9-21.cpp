#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "hello world my dear";
    istringstream iss(s);
    vector<string> vStr;
    string word;
    auto vB = vStr.begin();
    while (iss >> word)   
    {
        cout << word << endl;
        vB = vStr.insert(vB, word);
    }

    for (auto it = vStr.begin(); it != vStr.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}
