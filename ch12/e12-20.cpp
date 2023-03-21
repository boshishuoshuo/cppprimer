#include <iostream>
#include <fstream>

#include "my_StrBlob.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in("storyDataFile");
    string line;
    StrBlob b1;
    while(getline(in, line))
    {
        b1.push_back(line);
    }
    
    for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
        cout << it.deref() << endl;
    return 0;
}
