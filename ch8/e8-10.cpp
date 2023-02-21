#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "Please include the file" << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << argv[1] << " can not open." << endl;
        return -1;
    }
    vector<string> vLine;
    string line;
    while (getline(in, line))
    {
        vLine.push_back(line);
    }

    in.close();

    for (auto it = vLine.cbegin(); it != vLine.cend(); ++it)
    {
        istringstream sin(*it);
        string word;
        while (sin >> word)
        {
            cout << word << endl;
        }
    }

    return 0;
}
