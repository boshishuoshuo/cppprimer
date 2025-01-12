#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s1, s2;
    cout << "Enter 2 strings" << endl;
    cin >> s1 >> s2;
    if (s1 == s2) 
        cout << "the 2 strings are the same" << endl;
    else if (s1 > s2) 
        cout << "The bigger one is " << s1 << endl;
    else   
        cout << "The bigger one is " << s2 << endl;

    cout << "Enter another 2 strings" << endl;
    cin >> s1 >> s2;
    if (s1.size() == s2.size()) 
        cout << "the lengths of 2 strings are the same" << endl;
    else if (s1.size() > s2.size()) 
        cout << "The longer one is " << s1 << endl;
    else   
        cout << "The longer one is " << s2 << endl;

    return 0;
}