#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C>
void  print(const C &c)
{
    for (auto it = c.begin(); it != c.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    string s = "hello world";
    print(s);

    vector<int> vi = { 0, 2, 4, 5, 7};
    print(vi);
    return 0;
}
