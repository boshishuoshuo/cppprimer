#include <iostream>
#include <string>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string str1, str2;
    cout << "Please enter 2 strings; " << endl;
    cin >> str1 >> str2;
    if (str1 > str2)
        cout << "str1 is bigger" << endl;
    else if (str1 < str2)
        cout << "str2 is bigger" << endl;
    else   
        cout << "they are equal" << endl;
    char c1[80], c2[80];
    cout << "Please enter 2 chars" << endl;
    cin >> c1 >> c2;
    auto result =strcmp(c1, c2);
    switch (result)
    {
    case 1:
        cout << "c1 is bigger" << endl;
        break;
    case -1:
        cout << "c2 is bigger" << endl;
    case 0:
        cout << "They are the same" << endl;
    default:
        cout << result << endl;
        cout << "undefined" << endl;
        break;
    }
    return 0;

}
