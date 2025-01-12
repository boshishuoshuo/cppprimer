#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int num;
    char cont = 'y';
    while (cin >> num)
    {
        v.push_back(num);
        cout << "continue?" << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    if (v.size() == 0) return 0;
    int sum = v[0];
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i == 0) continue;
        sum += v[i];
        cout << "sum is "<< sum << endl;
        sum = v[i];
    }
    size_t l = v.size();
    size_t i = 0, j = l - 1;
    while (i <= j)
    {
        if (i == j) cout << "sum is " << v[i] << endl;
        else cout << "sum is " << v[i] + v[j] << endl;
        i++;
        j--;
    }
    return 0;
}