#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    char *r = new char[5];
    int l = 0;
    while(cin.get(c))
    {
        if (isspace(c)) break;
        r[l++] = c;
        if (l == 5)
        {
            cout << "reach limit" << endl;
            break;
        }
    }
    r[l] = 0;
    cout << r << endl;

    delete [] r;
    return 0;
}
