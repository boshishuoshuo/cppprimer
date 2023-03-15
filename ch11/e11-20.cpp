#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    istringstream iss("the red fox jumps over the green turtle");
    map<string, size_t> word_count;
    set<string> exclude = {"the", "over"};
    string word;
    while (iss >> word)    
    {
        if (exclude.find(word) == exclude.end())
        {
            auto ret = word_count.insert({word, 1});
            if (!ret.second)
                ++ret.first->second;
        }
        
    }
    for (const auto wd: word_count)
        cout << wd.first << " " << wd.second << endl;
    return 0;
}
