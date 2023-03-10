#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt = {1, 2, 44, 2, 5, 1, 4, 3, 2, 1, 1, };
    int c1, c2; 
    c1 = count(vInt.begin(), vInt.end(), 1);
    c2 = count(vInt.begin(), vInt.end(), 2);
    cout << "1 occurs " << c1 << " times" << endl;
    cout << "2 occurs " << c2 << " times" << endl;

    return 0;
}
