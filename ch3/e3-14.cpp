#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Please enter integers: " << endl;
    int i;
    vector<int> v;
    while(cin >> i)
    {
        v.push_back(i);
    }
    for (auto j: v)
    {
        cout << j << endl;
    }
    return 0;
}
