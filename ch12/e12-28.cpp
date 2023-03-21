#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> content_lines;
map<string, set<size_t>> word_map;

string cleanup_str(const string & s)
{
    string ret;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

void build_word_map(ifstream &in)
{
    string line;
    string word;
    size_t n = 1;
    while(getline(in, line))
    {
        content_lines.push_back(line);
        istringstream iss(line);
        while (iss >> word)
            word_map[cleanup_str(word)].insert(n);
        n++;
    }
}

void query(const string &sought)
{
    auto loc = word_map.find(sought);
    if (loc == word_map.end())
        cout << sought << " does not occur" << endl;
    else
    {
        cout << sought << " occurs in " << (loc->second).size() << " lines" << endl;
        for (auto n: loc->second)
        {
            cout << "\t" << "line[" << n << "] : " << content_lines[n-1] << endl; 
        }
    }
        
}

int main(int argc, char const *argv[])
{
    ifstream ifs("storyDataFile");
    build_word_map(ifs);
    query("she");
    return 0;
}
