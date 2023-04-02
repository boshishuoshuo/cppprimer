#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class StrLenIs
{
    public:
        StrLenIs(int l): len(l) {}
        bool operator()(const string &s) { return len == s.size(); }
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
    for (auto a : words)
        cout << a << " ";
    cout << endl;

    for (int i = 1; i <= 10; i++)
    {
        StrLenIs strlenis(i);
        cout << " len: " << i << ", cnt: " << count_if(words.begin(), words.end(), strlenis) << endl;
    }

    return 0;
}
