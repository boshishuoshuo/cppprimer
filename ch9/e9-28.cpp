#include <iostream>
#include <forward_list>

using namespace std;

void test_and_insert(forward_list<string> & fls, string & s1, string & s2)
{
    auto curr = fls.begin();
    auto prev = fls.before_begin();
    bool inserted = false;

    while (curr != fls.end())
    {
        if (*curr == s1)
        {
            curr = fls.insert_after(curr, s2);
            inserted = true;
        }
        prev = curr;
        ++curr;
    }

    if (!inserted)
    {
        fls.insert_after(prev, s2);
    }

}

void print_fl(forward_list<string> & fl)
{
    for (auto it = fl.begin(); it != fl.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    forward_list<string> fl_1 = {"hello", "world", "!", "my", "dear"};
    string to_replace = "world";
    string to_add = "aha";
    test_and_insert(fl_1, to_replace, to_add);
    print_fl(fl_1);

    to_replace = "zoe";
    to_add = "mia";

    test_and_insert(fl_1, to_replace, to_add);
    print_fl(fl_1);

    return 0;
}
