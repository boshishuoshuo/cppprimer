#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "ab cd ed ed Fc Fc bd";
    istringstream iss(s);
    string word, preWord = "";
    int flag = 0;
    while (iss >> word)
    {
        if (!isupper(word[0])) continue;
        if (word == preWord)
        {
            flag = 1;
            break;
        } else
        {
            preWord = word;
        }
    }
    if (flag)
    {
        cout << "The word occurs twice is " << preWord << endl;
    } else 
    {
        cout << "No repeated words" << endl;
    }

    return 0;
}
