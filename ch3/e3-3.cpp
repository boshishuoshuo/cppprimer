#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string word, line;
    cout << "please enter 1: by word; 2: by line" << endl;
    char ch;
    cin >> ch;
    if (ch == '1') 
    {
        cout << "enter :     Welcome to C++ family!    " << endl;
        cin >> word;
        cout << "word is "<< endl;
        cout << word << endl;
        return 0;
    }
    cin.clear();
    cin.sync();
    if (ch == '2')
    {
        cout << "enter :     Welcome to C++ family!    " << endl;
        getline(cin, line);
        cout << "line is "<< endl;
        cout << line << endl;
        return 0;
    }

    cout << "wrong input"<< endl;
    return -1;
}