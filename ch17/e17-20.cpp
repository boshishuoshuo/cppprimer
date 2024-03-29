#include <iostream>
#include <regex>
#include <string>
#include <sstream>

using namespace std;

bool valid(const smatch &m)
    {
        if(m[1].matched)
            return m[3].matched 
                    && (m[4].matched == 0 || m[4].str() == " ");
        else
            return !m[3].matched
                    && m[4].str() == m[6].str();
    }

int main(int argc, char const *argv[])
{
    string phone = 
        "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    smatch m;
    string s;
    istringstream iss("612-240-5073 (612-240-5073");
    while (iss >> s)
    {
        for (sregex_iterator it(s.begin(), s.end(), r), end_it;
                it != end_it; it++)
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else   
                cout << "not valild: " << it->str() << endl;
    }
    return 0;
}
