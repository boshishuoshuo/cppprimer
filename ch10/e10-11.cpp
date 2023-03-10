#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline void printout(vector<string> & words)
{
    cout << words.size() << endl;
    for (auto it = words.begin(); it != words.end(); ++it)
        cout << *it << " ";
    //for (int i = 0; i < words.size(); ++i)
    //    cout << words[i] << endl;
    cout << endl;
}

bool isShorter(const string & s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> & words)
{
    printout(words);
    sort(words.begin(), words.end());
    printout(words);
    auto end_unique = unique(words.begin(), words.end());
    printout(words);
    words.erase(end_unique, words.end());
    printout(words);

    stable_sort(words.begin(), words.end(), isShorter);
    printout(words);
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    
    return 0;
}
