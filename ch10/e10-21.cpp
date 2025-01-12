#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 5;
    auto f = [i]() mutable -> bool {if (i > 0) {--i; return false;} else {return true;}};
    for (int j = 0; j < 6; ++j)
        cout << f() << " ";
    cout << endl;

    int m = 5;
    auto f1 = [&m]() -> bool {if (m > 0) {--m; return false;} else {return true;}};
    for (int j = 0; j < 6; ++j)
        cout << f1() << " ";
    cout << endl;
    return 0;
}
