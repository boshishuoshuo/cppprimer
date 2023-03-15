#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream ifs("helloworld.txt");
    string line;
    map<string, list<int>> wordmap;
    int lineno = 1;
    while (getline(ifs, line))
    {
        string word;
        istringstream iss(line);
        while (iss >> word)
        {
            wordmap[word].push_back(lineno);
        }
        ++lineno;
    }
    for (auto w: wordmap)
    {
        cout << w.first << " appears at ";
        for (auto i: w.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
