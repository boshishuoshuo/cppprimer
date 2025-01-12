#include <iostream>
#include <string>

using namespace std;

template<typename T, size_t N>
void print_array(const T (&a)[N])
{
    for (auto iter = begin(a); iter != end(a); iter++)
        cout << *iter << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int a[6] = {0, 2, 4, 6, 8, 10};
    string s[3] = {"hello", "world", "zoe"};
    print_array(a);
    print_array(s);
    return 0;
}
