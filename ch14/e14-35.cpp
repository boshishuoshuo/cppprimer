#include <iostream>
#include <sstream>
#include <string>

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
    string s = "hello world";
    istringstream iss(s);
    ReadString readS(iss);
    cout << readS() << endl;
    return 0;
}
