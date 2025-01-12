#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

istream & s(istream & in)
{
    string v;
    while (in >> v, !in.eof())
    {
        if (in.bad())
            throw runtime_error("IO stream error");
        if (in.fail())
        {
            cerr << "Data error, retry: " << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main(int argc, char const *argv[])
{
    ostringstream msg;
    msg << "one two three four five" << endl;
    istringstream in(msg.str());
    s(in);
    return 0;
}
