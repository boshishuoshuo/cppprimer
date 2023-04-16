#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>

#include "Sales_data.h"

using namespace std;

typedef tuple<vector<Sales_data>::size_type, 
            vector<Sales_data>::const_iterator,
            vector<Sales_data>::const_iterator> matches;

vector<matches>
findBook(const vector<vector<Sales_data>> &files,
            const string &book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = equal_range(it->cbegin(), it->cend(),
                                book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
    }
    return ret;
}

void reportResults(istream &in, ostream &os, 
                    const vector<vector<Sales_data>> &files)
{
    string s;
    while (in >> s)
    {
        auto trans = findBook(files, s);
        if (trans.empty())
        {
            cout << s << " not found in any stores" << endl;
            continue;
        }
        for (const auto &store: trans)
        {
            os << "store " << get<0>(store) << " sales: "
                << accumulate(get<1>(store), get<2>(store), Sales_data(s))
            << endl;
            
        }
    }
}

vector<Sales_data> build_store(const string &s)
{
    Sales_data item;
    vector<Sales_data> ret;
    ifstream is(s);
    while(read(is, item))
        ret.push_back(item);
    sort(ret.begin(), ret.end());
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<vector<Sales_data>> files;
    files.push_back(build_store("store1"));
    files.push_back(build_store("store2"));
    files.push_back(build_store("store3"));
    files.push_back(build_store("store4"));
    istringstream iss("0-399-82477-1");
    reportResults(iss, cout, files);
    return 0;
}
