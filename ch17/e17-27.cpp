#include <iostream>
#include <sstream>
#include <regex>
#include <string>


using namespace std;


int main(int argc, char const *argv[])
{
    string zip = "(\\d{5})((-)?(\\d{4}))?";
    regex r(zip);
    string s = "123456789 12345-6789 123-5667 ";
    string fmt = "$1-$2";
    istringstream iss("123456789 12345-6789");
    for (sregex_iterator it(s.begin(), s.end(), r), end_it;
        it != end_it; ++it)
        if ((*it)[2].matched && (*it)[2].str()[0] != '-')
            cout << (*it).format(fmt) << endl;
        else
            cout << (*it).str() << endl;
    return 0;
}
