#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> scores(11, 0);
    vector<unsigned> vGrades = {45, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
    auto scoresBegin = scores.begin();
    for (auto it = vGrades.begin(); it != vGrades.end(); it++)
    {
        ++*(scoresBegin + *it/10);
    }
    for (auto it2 = scores.begin(); it2 != scores.end(); it2++)
    {
        cout << *it2 << " ";
    }
    cout << endl;
    return 0;
}