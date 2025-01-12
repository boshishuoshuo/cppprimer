#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

class IsShorter
{
    public:
        bool operator()(const string &s1, const string &s2)
        {
            return s1.size() < s2.size();
        }
};

class NotShorterThan
{
    public:
        NotShorterThan(int len): minLen(len) {}
        bool operator()(const string &str) {return str.size() >= minLen; }
    private:
        int minLen;
};

class PrintString
{
    public:
        void operator()(const string &str)
        {
            cout << str << " ";
        }
};

void biggies(vector<string> &words, size_t sz)
{
    elimDups(words);

    IsShorter is;
    stable_sort(words.begin(), words.end(), is);

    NotShorterThan nst(sz);
    auto wc = find_if(words.begin(), words.end(), nst);

    auto count = words.end() - wc;
    cout << count << " " << sz << " or longer" << endl;

    PrintString ps;
    for_each(wc, words.end(), ps);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ifstream ifs("storyDataFile");
    vector<string> words;
    string word;
    while (ifs && ifs >> word)
    {
        words.push_back(word);
    }
    biggies(words, 5);
    return 0;
}
