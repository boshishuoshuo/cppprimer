#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

typedef vector<string>::size_type line_no;
typedef set<line_no>::const_iterator line_it;
typedef tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>> QueryResult;

ostream& print(ostream& os, const QueryResult &res)
{
    cout << get<0>(res) << " occurs in " << get<1>(res)->size() << " lines" << endl;
    if (get<1>(res)->size() > 0)
    {
        for (auto i: *get<1>(res))
        {
            cout << "\t" << "line[" << i << "] : " << *(get<2>(res)->begin() + i - 1) << endl; 
        }
    }
    return os;
}

class TextQuery
{
    public:
        TextQuery(ifstream & in);

        QueryResult query(const string &) const;
    private:
        shared_ptr<vector<string>> content_lines;
        map<string, shared_ptr<set<line_no>>> word_map;
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
    line_no n = 1;
    while(getline(in, line))
    {
        content_lines->push_back(line);
        istringstream iss(line);

        while (iss >> word)
        {
            auto &lineNos = word_map[cleanup_str(word)];
            if (!lineNos)
                lineNos.reset(new set<line_no>);
            lineNos->insert(n);
        }
        n++;
    }
}

QueryResult TextQuery::query(const string & sought) const
{
    if (word_map.find(sought) == word_map.end())
    {
        shared_ptr<set<line_no>> nodata(new set<line_no>);
        return QueryResult(sought, nodata, content_lines);
    }
    return QueryResult(sought, word_map.find(sought)->second, content_lines);
}

int main(int argc, char const *argv[])
{
    ifstream ifs("storyDataFile");
    QueryResult qres = TextQuery(ifs).query("she");
    print(cout, qres);
    return 0;
}
