#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    auto sum = [](int a, int b) {return a + b;};
    cout << sum(1, 2) << endl;
    cout << sum(-100, 202) << endl;
    return 0;
}
