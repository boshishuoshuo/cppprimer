#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class QueryResult
{
    friend ostream& print(ostream&, QueryResult &);

    public:
        using line_no = vector<string>::size_type;
        QueryResult(const string & s, shared_ptr<set<line_no>> line_no_set, shared_ptr<vector<string>> line_str_vec):
        sought(s), lineNos(line_no_set), lines(line_str_vec) {}
        set<line_no>::const_iterator begin()
        {
            return lineNos->cbegin();
        }
        set<line_no>::const_iterator end()
        {
            return lineNos->cend();
        }
        shared_ptr<vector<string>> get_file()
        {
            return lines;
        }
    private:
        string sought;
        shared_ptr<set<line_no>> lineNos;
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
        using line_no = vector<string>::size_type;
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

class Query_base
{
    friend class Query;
    protected:
        using line_no = TextQuery::line_no;
        virtual ~Query_base() = default;
    private:
        virtual QueryResult eval(const TextQuery&) const = 0;
        virtual string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

    public:
        Query(const string&);
        QueryResult eval(const TextQuery &t) const
        { 
            cout << "Query eval ..." << endl;
            return q->eval(t); 
        }
        string rep() const
        { 
            cout << "Query rep ..." << endl;
            return q->rep(); 
        }

    private:
        Query(shared_ptr<Query_base> query) : q(query) 
        {
            cout << "private Query constructor." << endl;
        }
        shared_ptr<Query_base> q;
};

ostream & operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery: public Query_base
{
    friend class Query;
    WordQuery(const string &s) : query_word(s) 
    {
        cout << "Word Query constructor ... " << endl;
    }
    QueryResult eval(const TextQuery &t) const
    { return t.query(query_word);}
    string rep() const { return query_word;}
    string query_word;
};

inline
Query::Query(const string &s): q(new WordQuery(s)) 
{
    cout << "Public Query constructor ..." << endl;
}

class NotQuery: public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) 
    {
        cout << "NotQuery constructor ..." << endl;
    }
    string rep() const 
    {
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

class BinaryQuery: public Query_base
{
    protected:
        BinaryQuery(const Query &l, const Query &r, string s):
                lhs(l), rhs(r), opSym(s) 
        {
            cout << "Binary constructor ..." << endl;
        }
    string rep() const 
    {
        return "(" + lhs.rep() + " "
                    + opSym + " "
                    + rhs.rep() + ")";
    }
    Query lhs, rhs;
    string opSym;
};

class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
            BinaryQuery(left, right, "&") 
    {
        cout << "AndQuery constructor ..." << endl;
    }
    QueryResult eval(const TextQuery&) const;
};

inline 
Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult
AndQuery::eval(const TextQuery& text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                        inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery: public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
            BinaryQuery(left, right, "|") 
    {
        cout << "OrQuery constructor ..." << endl;
    }
    QueryResult eval(const TextQuery&) const;
};

inline 
Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult
OrQuery::eval(const TextQuery& text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult
NotQuery::eval(const TextQuery& text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if (beg == end || *beg!=n)
            ret_lines->insert(n);
        else if (beg!=end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

int main(int argc, char const *argv[])
{
    ifstream ifs("storyDataFile");
    TextQuery textquery = TextQuery(ifs);

    Query q = Query("fiery") & Query("bird") | Query("wind");
    
    QueryResult res = q.eval(textquery);
    cout << q.rep();

    print(cout, res);

    return 0;
}
