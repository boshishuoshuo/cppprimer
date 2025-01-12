#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std; 
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    vector<int> vInt1 = {128, 256, 512, 1024, 2048, 4096};
    auto wc = count_if(vInt1.begin(), vInt1.end(), bind(greater_equal<int>(), _1, 1024));
    cout << "in vInt1 cnt >= 1024: " << wc << endl;

    vector<string> vStr = {"poo", "pool", "pooh", "prr"};
    auto firstnotpooh = find_if(vStr.begin(), vStr.end(), bind(not_equal_to<string>(), _1, "pooh"));
    cout << *firstnotpooh << endl;

    vector<int> vInt2;
    vInt2.resize(vInt1.size());
    transform(vInt1.begin(), vInt1.end(), vInt2.begin(), bind(multiplies<int>(), _1, 2));
    for (int a: vInt2)
        cout << a << " ";
    cout << endl;
    return 0;
}
