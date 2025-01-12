#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StrLenIs
{
    public:
        StrLenIs(int l): len(l) {}
        bool operator()(const string &s) { return s.size() < len; }
    private:
        int len;
};

int main(int argc, char const *argv[])
{
    ifstream ifs("storyDataFile");
    vector<string> words;
    string word;
    while (ifs && ifs >> word)
    {
        words.push_back(word);
    }

        StrLenIs strlenis(5);
        cout << " word length <5 cnt: " << count_if(words.begin(), words.end(), strlenis) << endl;
        cout << " word length >=5 cnt: " << count_if(words.begin(), words.end(), [&strlenis](const string &s) {return !strlenis(s);}) << endl;

    return 0;
}
