#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v, unsigned index)
{
    unsigned vSize = v.size();
    #ifndef NDEBUG
        cout << vSize << endl;
    #endif
    if ( index < vSize)
    {
        
        cout << v[index] << endl;
        printVector(v, ++index);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vInt = {1, 3, 5, 7, 9, 11 ,13, 15, 17, 19};

    cout << "printing from index 0" <<endl;
    printVector(vInt, 0);

    cout << "printing from index 5" << endl;
    printVector(vInt, 5);

    cout << "printing from index 20" << endl;
    printVector(vInt, 20);

    return 0;
}
