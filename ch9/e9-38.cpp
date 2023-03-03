#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int s, c;

    for (s = v.size(), c = v.capacity(); s <=c ; ++s)
    {
        v.push_back(1);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <=c ; ++s)
    {
        v.push_back(1);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <=c ; ++s)
    {
        v.push_back(1);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <=c ; ++s)
    {
        v.push_back(1);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <=c ; ++s)
    {
        v.push_back(1);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    return 0;
}
