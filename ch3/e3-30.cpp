#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 0; ix < array_size; ++ix)
        ia[ix] = ix;    
    for (auto a: ia)
        cout << a << endl;
    return 0;
}
