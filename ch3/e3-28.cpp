#include <iostream>
#include <string>

using namespace std;

string sa[10];
int ia[10];

int main(int argc, char const *argv[])
{
    string sa2[10];
    int ia2[10];

    for (auto c: sa)
        cout << c << "|";

    for (auto c: ia)
        cout << c << " ";

    for (auto c: sa2)
        cout << c << "|";

    for (auto c: ia2)
        cout << c << " ";
    return 0;
}
