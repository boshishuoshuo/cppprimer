#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v1;
    cout << v1.size() << endl;
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v = {1, 2, 4, 5};

    vector<int> v2(v);
    cout << v2.size() << endl;
    for (auto it = v2.begin(); it != v2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7};
    cout << v3.size() << endl;
    for (auto it = v3.begin(); it != v3.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v4(v.begin()+2, v.end() - 1);
    cout << v4.size() << endl;
    for (auto it = v4.begin(); it != v4.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v5(7);
    cout << v5.size() << endl;
    for (auto it = v5.begin(); it != v5.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v6(7,3);
    cout << v6.size() << endl;
    for (auto it = v6.begin(); it != v6.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
