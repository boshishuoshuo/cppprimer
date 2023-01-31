#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);
    for (auto &c: s)
    {
        if (!(ispunct(c)))
            cout << c;
    }
    cout << endl;
    return 0;
}