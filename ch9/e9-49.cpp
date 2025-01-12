#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string getWord(const string &s, const string &chars)
{
    string res = "";
    int pos = 0;
    while((pos = s.find_first_of(chars, pos)) != string::npos)
    {
        res += s[pos];
        ++pos;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string word = "hello world my dear kid mia zoe experience";

    istringstream iss(word);

    string longestWord, tmpWord;
    int length = 0;

    while (iss >> tmpWord)
    {
        tmpWord = getWord(tmpWord, "acemnorsuvwxz");
        if (tmpWord.size() > length)
            longestWord = tmpWord;
    }
    cout << "longest word: " << longestWord << endl;

    return 0;
}
