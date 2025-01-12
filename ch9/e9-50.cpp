#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vStr = {"1", "-2", "3"};
    int sum = 0;
    for (auto it = vStr.begin(); it != vStr.end(); ++it)
    {
        sum += stoi(*it);
    }
    cout << sum << endl;

    vector<string> vStr1 = {"12.3", "-4.56", "+7.8e-2"};
    double sum1 = 0.0;
    for (auto it = vStr1.begin(); it != vStr1.end(); ++it)
    {
        sum1 += stod(*it);
    }
    cout << sum1 << endl;
    return 0;
}
