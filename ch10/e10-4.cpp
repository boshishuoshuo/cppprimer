#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<double> vInt = {0.0, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1};
    double sum;
    sum = accumulate(vInt.begin(), vInt.end(), 0.0);
    cout << "The sume of vInt is " << sum << endl;
    return 0;
}
