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

template<typename T, size_t N>
const T* my_begin(const T (&a)[N])
{
    return &a[0];
}

template<typename T, size_t N>
const T* my_end(const T (&a)[N])
{
    return &a[0] + N;
}

int main(int argc, char const *argv[])
{
    int a[6] = {0, 2, 4, 6, 8, 10};
    string s[3] = {"hello", "world", "zoe"};
    print_array(a);
    print_array(s);

    cout << *my_begin(a) << endl;
    cout << *(my_end(a) - 1) << endl;
    cout << *my_begin(s) << endl;
    cout << *(my_end(s) - 1)<< endl;

    return 0;
}
