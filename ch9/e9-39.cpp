#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> v;
    v.reserve(8);
    string s1 = "hello", s2 = "world";
    v.push_back(s1);
    v.push_back(s2);
    v.resize(v.size() + v.size()/2);

    cout << "capacity: " << v.capacity() << endl;
    return 0;
}
