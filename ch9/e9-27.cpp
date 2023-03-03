#include <iostream>
#include <forward_list>

using namespace std;

int main(int argc, char const *argv[])
{
    forward_list<int> fl = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto prev = fl.before_begin();
    auto curr = fl.begin();

    while (curr != fl.end())
    {
        if (*curr & 1)
        {
            curr = fl.erase_after(prev);
        } else 
        {
            prev = curr;
            ++curr;
        }
    }

    for (auto it = fl.begin(); it != fl.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
