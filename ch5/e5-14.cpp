#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string line1 = "how now now now brown cow cow";
    string line2 = "how now brown cow";

    stringstream ss1(line1);

    string currStr1, prevStr1 = "", maxStr1;
    int currCnt1 = 1, maxCnt1 = 0; 
    while (ss1 >> currStr1)
    {
        if (currStr1 == prevStr1)
        {
            ++currCnt1;
            if (currCnt1 > maxCnt1)
            {
                maxStr1 = currStr1;
                maxCnt1 = currCnt1;
            }
        } else
        {
            prevStr1 = currStr1;
            currCnt1 = 1;
        }

    }
    if (maxCnt1 > 0 )
    {
        cout << "The most abundant string is " << maxStr1 << endl;
        cout << "The time of occurances is " << maxCnt1 << endl;
    } else 
    {
        cout << "all words occur only once" << endl;
    }

    stringstream ss2(line2);

    string currStr2, prevStr2 = "", maxStr2;
    int currCnt2 = 1, maxCnt2 = 0; 
    while (ss1 >> currStr1)
    {
        if (currStr2 == prevStr2)
        {
            ++currCnt2;
            if (currCnt2 > maxCnt2)
            {
                maxStr2 = currStr2;
                maxCnt2 = currCnt2;
            }
        } else
        {
            prevStr2 = currStr2;
            currCnt2 = 1;
        }

    }
    if (maxCnt2 > 0 )
    {
        cout << "The most abundant string is " << maxStr2 << endl;
        cout << "The time of occurances is " << maxCnt2 << endl;
    } else 
    {
        cout << "all words occur only once" << endl;
    }
    return 0;
}
