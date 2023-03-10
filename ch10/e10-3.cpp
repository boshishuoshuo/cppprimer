#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum;
    sum = accumulate(vInt.begin(), vInt.end(), 0);
    cout << "The sume of vInt is " << sum << endl;
    return 0;
}
