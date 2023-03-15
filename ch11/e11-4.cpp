#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

string & trans(string & s)
{
    for (int p = 0; p < s.size(); p++)
        if (isupper(s[p]))
            s[p] = tolower(s[p]);
        else if (s[p] == '.' || s[p] == ',')
            s.erase(p, 1);
    cout << s << endl;
    return s;
}

int main(int argc, char const *argv[])
{
    istringstream iss("The red fox jumps over the. green turtle");
    map<string, size_t> word_count;
    set<string> exclude = {"the", "over"};
    string word;
    while (iss >> word)    
    {
        word = trans(word);
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    for (const auto wd: word_count)
        cout << wd.first << " " << wd.second << endl;
    return 0;
}
