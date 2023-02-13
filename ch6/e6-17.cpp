#include <iostream>
#include <string>

using namespace std;

bool HasUpper(const string &s)
{
    for (auto c: s)
    {
        if (isupper(c)) return true;
    }
    return false;
}

void ChangeToLower(string &s)
{
    for (auto &c: s)
    {
        if(isupper(c)) c = tolower(c);
    }
}

int main(int argc, char const *argv[])
{
    string s = "hEllO, worLD";
    if (HasUpper(s)) cout << "it has upper case" << endl;
    ChangeToLower(s);
    cout << s << endl;
    return 0;
}
