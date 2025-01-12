#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename I, typename T> 
I find_value(I b, I e, const T &v)
{
    while(b != e && *b != v)
        b++;
    return b;
}

template<typename I>
void print_result(I b, I f, I e)
{
    if (f == e)
        cout << "not found" << endl;
    else
        cout << "found it at " << *f << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> vi = {0, 2, 4, 6, 8};
    list<string> ls = {"hello", "world", "zoe", "mia"};

    auto it1 = find_value(vi.begin(), vi.end(), 5);
    auto it2 = find_value(vi.begin(), vi.end(), 6);

    print_result(vi.begin(), it1, vi.end());
    print_result(vi.begin(), it2, vi.end());

    auto it3 = find_value(ls.begin(), ls.end(), "Hello");
    auto it4 = find_value(ls.begin(), ls.end(), "zoe");

    print_result(ls.begin(), it3, ls.end());
    print_result(ls.begin(), it4, ls.end());

    return 0;
}
