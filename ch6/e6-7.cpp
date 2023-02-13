#include <iostream>

using namespace std;

unsigned callCnt()
{
    static int cnt = -1;
    ++cnt;
    return cnt;
}

int main(int argc, char const *argv[])
{
    char ch;
    cout << "Enter to check the call counts:" << endl;
    while (cin >> ch)
    {
        cout << "The function called " << callCnt() << "times" << endl;
    }
    return 0;
}
