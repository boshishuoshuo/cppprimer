#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Please enter letters: " << endl;
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt= 0, uCnt = 0;
    unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char l;
    //char cont = 'y';

    while (cin.get(l))
    {
        switch(l)
        {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
        }
        //cout << "Continue? ";
        //cin >> cont;
        //if (cont != 'y' && cont != 'Y')
        //    break;
        //cout << "enter another letter: " ;
    }
    cout << "Number of vowel a is " << aCnt << endl;
    cout << "Number of vowel e is " << eCnt << endl;
    cout << "Number of vowel i is " << iCnt << endl;
    cout << "Number of vowel o is " << oCnt << endl;
    cout << "Number of vowel u is " << uCnt << endl;
    cout << "Number of space is " << spaceCnt << endl;
    cout << "Number of tab is " << tabCnt << endl;
    cout << "Number of newline is " << newlineCnt << endl;
    return 0;
}