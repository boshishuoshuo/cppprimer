#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> ilist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto curr = ilist.begin();

    while (curr != ilist.end())
    {
        if (*curr & 1)
        {
            curr = ilist.insert(curr, *curr);
            ++curr;
            ++curr;
        } else
        {
            curr = ilist.erase(curr);
        }
    }

    auto it = ilist.begin();
    while (it != ilist.end())
    {
        cout << *it++ << " ";
    }
    cout << endl;

    return 0;
}
