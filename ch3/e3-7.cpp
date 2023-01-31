#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);
    for (char &c: s)
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}