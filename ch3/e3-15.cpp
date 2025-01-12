#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> v;
    string s;
    char cont = 'y';
    while(cin >> s)
    {
        v.push_back(s);
        cout << "continue ? " << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto j: v)
    {
        cout << j << endl;
    }
    return 0;
}
