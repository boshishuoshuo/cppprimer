#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    char cont = 'y';
    string s, result;
    cout << "enter the first string: " << endl;
    while(cin >> s)
    {
        result += s;
        cout << "continue ? (y or n)" << endl;
        cin >> cont;
        if (cont == 'y')
            cout << "enter another string: " << endl;
        else
            break;
    }

    cout << "final string is " << result << endl;

    result = "";
    cout << "enter the first string: " << endl;
    while(cin >> s)
    {
        if (result.size() == 0)
            result = s;
        else
            result = result + " " + s;
        cout << "continue ? (y or n)" << endl;
        cin >> cont;
        if (cont == 'y')
            cout << "enter another string: " << endl;
        else
            break;
    }

    cout << "final string is " << result << endl;
    
    return 0;
}