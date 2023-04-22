#include <iostream>
#include <typeinfo>

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
    try
    {
        dynamic_cast<AndQuery*>(qb);
        cout << "success" << endl;
    }
    catch(bad_cast &bc)
    {
        cout << "failure" << endl;
    }
    Query_base *qb1;
    Query_base *qb2;
    
    if (typeid(qb1) == typeid(qb2)) 
        cout << "same" << endl;
    if (typeid(qb1) == typeid(AndQuery))
        cout << "identical" << endl;
    return 0;
}
