#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "ab cd ed ed";
    istringstream iss(s);
    string word, preWord = "";
    int flag = 0;
    while (iss >> word)
    {
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

    string s2 = "ab cd ed";
    istringstream iss2(s2);
    string word2, preWord2 = "";
    int flag2 = 0;
    while (iss2 >> word2)
    {
        if (word2 == preWord2)
        {
            flag2 = 1;
            break;
        } else
        {
            preWord2 = word2;
        }
    }
    if (flag2)
    {
        cout << "The word occurs twice is " << preWord2 << endl;
    } else 
    {
        cout << "No repeated words" << endl;
    }
    return 0;
}
