#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int main(int argc, char const *argv[])
{
    vector<string> vStr = {"hello", "world", "my", "dear", "zoe", "mia"};
    vector<int> size_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = vStr.begin(); it != vStr.end(); ++it)
    {
        auto g = bind(check_size, *it, _1);
        for (auto i = size_vec.begin(); i != size_vec.end(); ++i)
        {
            if (g(*i))
            {
                cout << *i << endl;
                break;
            }
        }
    }
    
    return 0;
}
