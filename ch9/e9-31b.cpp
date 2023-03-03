#include <iostream>
#include <forward_list>

using namespace std;

int main(int argc, char const *argv[])
{
    forward_list<int> iflist = {0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 8, 9};
    auto prev = iflist.before_begin();
    auto curr = iflist.begin();

    while (curr != iflist.end())
    {
        if (*curr & 1)
        {
            curr = iflist.insert_after(curr, *curr);
            prev = curr;
            ++curr;
        } else
        {
            curr = iflist.erase_after(prev);
        }
    }

    auto it = iflist.begin();
    while (it != iflist.end())
    {
        cout << *it++ << " ";
    }
    cout << endl;
    return 0;
}
