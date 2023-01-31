#include <iostream>
#include <vector>
#include <string>

using namespace std;

string toUpperString(string &s)
{
    for (char &c : s)
    {
        c = toupper(c);
    }
    return s;
}

int main(int argc, char const *argv[])
{
    vector<string> v;
    string word;
    char cont = 'y';
    while (cin >> word)
    {
        v.push_back(word);
        cout << "continue?" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto e: v)
    {
        cout << toUpperString(e) << endl;
    }
    return 0;
}
