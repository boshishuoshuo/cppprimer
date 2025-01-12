#include <iostream>

#include "my_StrBlob.h"

using namespace std;

int main(int argc, char const *argv[])
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << "b2 size: " << b2.size() << endl;
        cout << "b2 first and end " << b2.front() << " " << b2.back() << endl;
    }
    cout << "b1 size: " << b1.size() << endl;
    cout << "b1 first and end " << b1.front() << " " << b1.back() << endl;

    StrBlob b3 = b1;
    b3.push_back("next");
    cout << "b3 size: " << b3.size() << endl;
    cout << "b3 first and end " << b3.front() << " " << b3.back() << endl;

    cout << "b1 all elements: " << endl;
    for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
    {
        cout << it.deref() << endl;
    }

    return 0;
}
