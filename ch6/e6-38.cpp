#include <iostream>

using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = { 2, 4, 6, 8, 0};

decltype(odd) &arrRef(int i)
{
    return (i % 2) ? odd : even;
}

int main(int argc, char const *argv[])
{
    int aSize = sizeof(arrRef(2));
    cout << aSize << endl;

    int iSize = sizeof(arrRef(2)[0]);
    cout << iSize << endl;
    
    int arrSize = aSize / iSize;

    for (int i = 0; i != arrSize; ++i)
    {
        cout << arrRef(2)[i] << endl;
        cout << arrRef(3)[i] << endl;
    }
    cout << arrRef(2) << endl;


    return 0;
}
