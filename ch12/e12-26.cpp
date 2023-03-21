#include <iostream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    string s;
    string *q = p;
    istringstream iss("hello world mia zoe");
    while (iss >> s && q != p + 10)
    {
        alloc.construct(q++, s);

    }
    
    cout << *--q << endl;
    cout << endl;
    const size_t size = q - p;
    for (size_t i = 0; i < size; i++)
        cout << p[i] << " " << endl;
    while (q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, 10);
    return 0;
}
