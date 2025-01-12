#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = 'X';
        i++;
    }
    cout << s << endl;

    cout << "Enter another string: " << endl;
    getline(cin, s);
    for (unsigned i = 0; i < s.size(); i++)
    {
        s[i] = 'X';
    }
    cout << s << endl;
    return 0;
}