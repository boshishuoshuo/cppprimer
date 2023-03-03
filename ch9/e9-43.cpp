#include <iostream>
#include <string>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    auto iter = s.begin();
    int oldSize = oldVal.size();
    if (oldSize == 0) return ;
    int newSize = newVal.size();
    while (iter <= s.end() - oldSize)
    {
        string s_part(iter, iter + oldSize);
        if (s_part == oldVal)
        {
            iter = s.erase(iter, iter + oldSize);
            if (newSize != 0)
            {
                iter = s.insert(iter, newVal.begin(), newVal.end());
                iter += newSize;
            }
                
            
        } else 
        {
            ++iter;
        }
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
