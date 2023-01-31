#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        *it *= 2;
        cout << *it << endl;
    }
    
    return 0;
}