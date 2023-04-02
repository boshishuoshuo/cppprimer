#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ReadString
{
    public:
        ReadString(istream &is = cin) : is(is) {}
        string operator()()
        {
            string line;
            if (!getline(is, line))
            {
                line = "";
            }
            return line;
        }

    private:
        istream &is;
};

int main(int argc, char const *argv[])
{
    ifstream ifs("storyDataFile");
    vector<string> vS;
    ReadString readS(ifs);
    while (true)
    {
        string line = readS();
        if (line.empty()) break;
        vS.push_back(line);
    }
        
    for (auto s: vS)
        cout << s << endl;
    return 0;
}
