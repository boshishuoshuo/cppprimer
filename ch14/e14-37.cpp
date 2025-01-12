#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IntComp
{
    public:
        IntComp(int v): val(v) {}
        bool operator()(int value) { return value == val; }

    private:
        int val;
};


int main(int argc, char const *argv[])
{
    vector<int> vInt= {1, 2, 2, 4, 5, 1, 4};
    for (auto a: vInt)
        cout << a << " ";
    cout << endl;
    int oldVal = 2;
    int newVal = 200;
    IntComp intcomp(2);
    replace_if(vInt.begin(), vInt.end(), intcomp, newVal);
    for (auto a: vInt)
        cout << a << " ";
    cout << endl;
    return 0;
}
