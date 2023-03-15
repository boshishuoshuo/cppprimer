#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    istringstream iss("the red fox jumps over the green turtle");
    unordered_map<string, size_t> word_count;
    set<string> exclude = {"the", "over"};
    string word;
    while (iss >> word)    
    {
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    for (const auto wd: word_count)
        cout << wd.first << " " << wd.second << endl;
    return 0;
}
