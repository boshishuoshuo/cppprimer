#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;

shared_ptr<vector<int>> genVec()
{
    return make_shared<vector<int>>();
}

void readVec(shared_ptr<vector<int>> pv)
{
    istringstream iss("1 2 3 4 5 6 7 8 9");
    int n;
    while (iss >> n)
    {
        pv->push_back(n);
    }
}

void printVec(shared_ptr<vector<int>> pv)
{
    for (const auto &i : *pv)
        cout << i << endl;
}

int main(int argc, char const *argv[])
{
    shared_ptr<vector<int>>  pv = genVec();
    if (!pv) return -1;
    readVec(pv);
    printVec(pv);
    return 0;
}
