#include <iostream>

#include "my_StrBlob.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const StrBlob b1 = {"hello", "world", "!"};
    
    for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
        cout << it.deref() << endl;
    return 0;
}
