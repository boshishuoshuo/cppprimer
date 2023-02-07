#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Please enter a letter: " << endl;
    unsigned vowelCnt = 0;
    char l;
    char cont = 'y';

    while (cin >> l)
    {
        if ( l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
        {
            ++vowelCnt;
        }
        cout << "Continue? " << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    cout << "Number of vowel is " << vowelCnt << endl;
    return 0;
}
