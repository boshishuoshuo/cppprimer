#include "Chapter6.h"

using namespace std;

int fact(int i)
{
    if (i == 0 || i == 1) return 1;
    int result = 1;
    for (int j = 1; j <= i; ++j)
    {
        result *= j;
    }
    return result;
}