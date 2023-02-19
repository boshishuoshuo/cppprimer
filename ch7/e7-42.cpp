#include <iostream>
#include <string>

using namespace std;

class Book
{
    friend istream & operator >> (istream &, Book &);
    private:
        string Name, ISBN, Author, Publisher;
        double Price = 0;
    public:
        Book(const string &n, const string &I, double pr, const string &a, const string &p) 
        {
            Name = n;
            ISBN = I;
            Price = pr;
            Author = a;
            Publisher = p;
        }
        Book() : Book("", "", 0, "", "") {}
        Book(istream &is) {is >> *this;}
};