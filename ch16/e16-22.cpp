#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class DebugDelete
{
    public:
        DebugDelete(ostream &s = cerr) : os(s) {}
        template <typename T> void operator()(T *p) const
        {
            os << "deleting shared_ptr" << endl;
            delete p;
        }
    private:
        ostream &os;
};

class QueryResult
{
    friend ostream& print(ostream&, QueryResult &);

    public:
        QueryResult(const string & s, shared_ptr<set<size_t>> line_no_set, shared_ptr<vector<string>> line_str_vec):
        sought(s), lineNos(line_no_set), lines(line_str_vec) {}
    private:
        string sought;
        shared_ptr<set<size_t>> lineNos;
        shared_ptr<vector<string>> lines;
};

ostream& print(ostream& os, QueryResult &res)
{
    cout << res.sought << " occurs in " << res.lineNos->size() << " lines" << endl;
    if (res.lineNos->size() > 0)
    {
        for (auto i: *res.lineNos)
        {
            cout << "\t" << "line[" << i << "] : " << *(res.lines->begin() + i - 1) << endl; 
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

TextQuery::TextQuery(ifstream & in): content_lines(new vector<string>, DebugDelete())
{
    string line;
    string word;
    size_t n = 1;
    while(getline(in, line))
    {
        content_lines->push_back(line);
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

QueryResult TextQuery::query(const string & sought) const
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
    QueryResult qres = TextQuery(ifs).query("she");
    print(cout, qres);
    return 0;
}
