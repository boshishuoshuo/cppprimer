#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char const *p[] = {"hello", "world", "!"};
    char *q[] = {strdup(p[0]), strdup(p[1]), strdup(p[2])};
    char const *r[] = {p[0], p[1], p[2]};
    cout << equal(begin(p), end(p), q) << endl;
    cout << equal(begin(p), end(p), r) << endl;

    return 0;
}
