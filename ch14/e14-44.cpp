#include <iostream>
#include <functional>
#include <map>
#include <string>

using namespace std;

map<string, function<int (int, int)>> binOps = 
{
    {"+", plus<int>()},
    {"-", minus<int>()},
    {"*", multiplies<int>()},
    {"/", divides<int>()},
    {"%", modulus<int>()},
};

int main(int argc, char const *argv[])
{
    int a = 3, b = 2;
    cout << "3 + 2 = " << binOps["+"](a, b) << endl;
    cout << "3 - 2 = " << binOps["-"](a, b) << endl;
    cout << "3 * 2 = " << binOps["*"](a, b) << endl;
    cout << "3 / 2 = " << binOps["/"](a, b) << endl;
    cout << "3 % 2 = " << binOps["%"](a, b) << endl;

    return 0;
}
