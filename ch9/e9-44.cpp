#include <iostream>
#include <string>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    if (oldVal.size() == 0) return;
    int p = 0;
    while ((p = s.find(oldVal, p)) != string::npos)
    {
        s.replace(p, oldVal.size(), newVal);
        p += newVal.size();
    }
}

int main(int argc, char const *argv[])
{
    string s = "tho thru tho!";
    replace_string(s, "thru", "through");
    cout << s << endl;

    replace_string(s, "tho", "though");
    cout << s << endl;

    replace_string(s, "through", "");
    cout << s << endl;
    return 0;
}
