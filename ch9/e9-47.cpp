#include <iostream>
#include <string>

using namespace std;

string find_char(string &s, const string & chars)
{
    string res = "";
    int pos = 0;
    while ((pos = s.find_first_of(chars, pos)) != string::npos)
    {
        res += s[pos];
        ++pos;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "a2c3d7R4E6";
    cout << find_char(s, "0123456789") << endl;

    s = "abcd";
    cout << find_char(s, "0123456789") << endl;

    s = "0234";
    cout << find_char(s, "0123456789") << endl;

    s = "a2c3d7R4E6";
    cout << find_char(s, "abcdefghigklmnopqrstuvwxyz"\
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ") << endl;

    s = "abcd";
    cout << find_char(s, "abcdefghigklmnopqrstuvwxyz"\
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ") << endl;

    s = "0234";
    cout << find_char(s, "abcdefghigklmnopqrstuvwxyz"\
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ") << endl;

    return 0;
}
