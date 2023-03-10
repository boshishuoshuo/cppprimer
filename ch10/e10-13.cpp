#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool longerThan5(const string & s)
{
    return s.size() >= 5;
}

void printVec(vector<string> & vs)
{
    for (auto it = vs.begin(); it != vs.end(); ++it)
        cout << *it << " " ;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<string> vS = {"hello", "world", "my", "dear", "zoefeng", "miafeng"};
    printVec(vS);

    auto it = partition(vS.begin(), vS.end(), longerThan5);

    printVec(vS);

    vS.erase(it, vS.end());

    printVec(vS);

    return 0;
}
