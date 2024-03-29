#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Query_base
{
    public:
        Query_base() {}
        virtual ~Query_base() {}
};

class BinaryQuery: public Query_base
{
    public:
        BinaryQuery() {}
        virtual ~BinaryQuery() {}
};

class AndQuery: public BinaryQuery
{
    public:
        AndQuery() {}
        virtual ~AndQuery() {}
};

int main(int argc, char const *argv[])
{
    
    Query_base *qb = new Query_base();
    if (dynamic_cast<AndQuery*>(qb) != NULL)
        cout << "success" << endl;
    else    
        cout << "failure" << endl;

    return 0;
}
