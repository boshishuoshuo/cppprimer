#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    istringstream iss("hello world my dear my zoe my mia");
    vector<string> vStr;
    string word;
    while (iss >> word)
    {
        if (find(vStr.begin(), vStr.end(), word) == vStr.end())
            vStr.push_back(word);
    }
    ostream_iterator<string> oit(cout, " ");
    copy(vStr.begin(), vStr.end(), oit);
    cout << endl;
    return 0;
}
