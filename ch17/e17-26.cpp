#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;
using std::regex_constants::format_no_copy;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

string format(const string &s) 
{
    string phone = 
        "(\\()?(\\d{3})(\\))?([-.]|\\s*)?(\\d{3})([-.]|\\s*)?(\\d{4})";
    regex r(phone);
    smatch m;
    string ret;
    string fmt = "$2.$5.$7";
    ret = regex_replace(s, r, fmt, format_no_copy);
    return ret;
}

bool valid(const smatch &m)
{
    if(m[1].matched)
        return m[3].matched 
                && (m[4].matched == 0 || (m[4].str() != "-" && m[4] != "."));
    else
        return !m[3].matched
                && ( (m[4].str() == "-" && m[6].str() == "-")
                    || (m[4].str() == "." && m[6].str() == ".")
                    || (m[4].str() != "-" && m[4].str() != "."
                        && m[6].str() != "-" && m[6].str() != ".")
                    );
}

vector<PersonInfo>
getData(istream &is)
{
    string phone = 
        "(\\()?(\\d{3})(\\))?([-.]|\\s*)?(\\d{3})([-.]|\\s*)?(\\d{4})";
    regex r(phone);
    smatch m;
    string line, word;
    
    vector<PersonInfo> people;

    while (getline(is, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        getline(record, line);
        sregex_iterator it(line.begin(), line.end(), r), end_it;
        
        for(it++; it!= end_it; it++)
            if (it != end_it && valid(*it))
                info.phones.push_back("V" + it->str());
            else   
                info.phones.push_back("I" + it->str());
        people.push_back(info);
    }
    return people;
}

ostream & process(ostream &os, vector<PersonInfo> people)
{
    for (const auto &entry: people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums: entry.phones)
        {
            if (nums[0] == 'I')
            {
                badNums << " " << nums.substr(1) << endl;
            } else
            {
                formatted << " " << format(nums.substr(1)) << endl;
            }
        }
        if (badNums.str().empty())
            os << entry.name << endl
                << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                << " invalid number(s) " << badNums.str() << endl;
    }
    return os;
}

int main(int argc, char const *argv[])
{
    ifstream ifs("phones");
    process(cout, getData(ifs));
    return 0;
}

