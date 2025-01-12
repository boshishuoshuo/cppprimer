#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = vInt.crbegin(); it != vInt.crend(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
