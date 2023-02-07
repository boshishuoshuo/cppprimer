#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prech = '\0';
    cout << "enter letters: " << endl;

    while (cin >> ch)
    {
        bool bl = true;
        if (prech == 'f')
        {
            switch (ch)
            {    case 'f':
                    ++ffCnt;
                    bl = false;
                    break;
                case 'l':
                    ++flCnt;
                    bl = false;
                    break;
                case 'i':
                    ++fiCnt;
                    bl = false;
                    break;
            }
        }
        if (bl)
            prech = ch;
        else   
            prech = '\0';
    }
    cout << "ff count: " << ffCnt << endl;
    cout << "fl count: " << flCnt << endl;
    cout << "fi count: " << fiCnt << endl;
    return 0;
}
