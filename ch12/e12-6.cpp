#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> * genVec()
{
    return new (nothrow) vector<int>;
}

void readVec(vector<int> * pv)
{
    istringstream iss("1 2 3 4 5 6 7 8 9");
    int n;
    while (iss >> n)
    {
        pv->push_back(n);
    }
}

void printVec(vector<int> * pv)
{
    for (const auto &i : *pv)
        cout << i << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> * pv = genVec();
    if (!pv) return -1;
    readVec(pv);
    printVec(pv);
    delete pv;
    return 0;
}
