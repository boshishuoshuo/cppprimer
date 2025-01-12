#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    vector<int> vInt = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1; i< 10; i++)
    {
        auto m = count_if(vInt.begin(), vInt.end(), [&i](int a){ return modulus<int>()(a, i) == 0;});
        cout << "there are " << m << " can be divided by " << i << endl;
     }
    return 0;
}
