#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in("e8-1.cpp");
    if (!in)
    {
        cerr << "can not open e8-1.cpp" << endl;
        return -1;
    }
    string line;
    vector<string> vLines;

    while (getline(in, line))
    {
        vLines.push_back(line);
    }

    in.close();
    
    for (auto it = vLines.cbegin(); it != vLines.cend(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}
