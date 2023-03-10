#include <iostream>

using namespace std;

void addNum(int a)
{
    auto sum = [a](int b) {return a + b;};
    cout << sum(1) << endl;
    cout << sum(100) << endl;
}

int main(int argc, char const *argv[])
{
    addNum(20);
    addNum(30);
    return 0;
}
