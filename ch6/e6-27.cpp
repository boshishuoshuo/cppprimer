#include <iostream>

using namespace std;

int customSum(initializer_list<int> lst)
{
    int sum = 0;
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        sum += *it;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    cout << customSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
    return 0;
}
