#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "my_StrBlob.h"

using namespace std;



class TextQuery
{
    public:
        TextQuery(ifstream & in);
        class QueryResult;
        QueryResult query(const string &) const;
    private:
        StrBlob content_lines;
        map<string, shared_ptr<set<size_t>>> word_map;
};

string cleanup_str(const string & s)
{
    string ret;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

TextQuery::TextQuery(ifstream & in): content_lines(new vector<string>)
{
    string line;
    string word;
    size_t n = 1;
    while(getline(in, line))
    {
        content_lines.push_back(line);
        istringstream iss(line);

        while (iss >> word)
        {
            auto &lineNos = word_map[cleanup_str(word)];
            if (!lineNos)
                lineNos.reset(new set<size_t>);
            lineNos->insert(n);
        }
        n++;
    }
}

class TextQuery::QueryResult
{
    friend ostream& print(ostream&, QueryResult &);

    public:
        QueryResult(const string & s, shared_ptr<set<size_t>> line_no_set, StrBlob line_str_vec):
        sought(s), lineNos(line_no_set), lines(line_str_vec) {}
    private:
        string sought;
        shared_ptr<set<size_t>> lineNos;
        StrBlob lines;
};

ostream& print(ostream& os, TextQuery::QueryResult &res)
{
    cout << res.sought << " occurs in " << res.lineNos->size() << " lines" << endl;
    if (res.lineNos->size() > 0)
    {
        for (auto i: *res.lineNos)
        {
            cout << "\t" << "line[" << i << "] : " << StrBlobPtr(res.lines, i-1).deref() << endl; 
        }
    }
    return os;
}

TextQuery::QueryResult TextQuery::query(const string & sought) const
{
    if (word_map.find(sought) == word_map.end())
    {
        shared_ptr<set<size_t>> nodata(new set<size_t>);
        return QueryResult(sought, nodata, content_lines);
    }
    return QueryResult(sought, word_map.find(sought)->second, content_lines);
}

int main(int argc, char const *argv[])
{
    ifstream ifs("storyDataFile");
    TextQuery tq(ifs);
    TextQuery::QueryResult qres = tq.query("she");
    print(cout, qres);
    return 0;
}
