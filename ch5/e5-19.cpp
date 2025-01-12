#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s1, s2;
    char cont = 'y';
    do 
    {
        cout << "Please enter 2 strings: " << endl;
        cin >> s1 >> s2;
        if (s1.size() <= s2.size())
        {
            cout << "The shorter string is " << s1 << endl;
        } else
        {
            cout << "The shorter string is " << s2 << endl;
        }
        cout << "Continue? " << endl;
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
