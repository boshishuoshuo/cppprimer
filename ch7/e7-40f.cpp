#include <iostream>

using namespace std;

class Tree
{
    private:
        string Name;
        unsigned Age = 0;
        double Height = 0;
    public:
        Tree() = default;
        Tree(const string &n, const unsigned a, const double h) : Name(n), Age(a), Height(h) {};
};