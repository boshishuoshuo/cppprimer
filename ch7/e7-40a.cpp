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
        Book() = default;
        Book(const string &n, const string &I, double pr, const string &a, const string &p) 
        {
            Name = n;
            ISBN = I;
            Price = pr;
            Author = a;
            Publisher = p;
        }
        Book(istream &is) {is >> *this;}
};

istream & operator >> (istream & is, Book & myBook)
{
    is >> myBook.Name >> myBook.ISBN >> myBook.Author >> myBook.Publisher >> myBook.Price;
    return is;
}

int main()
{
    return 0;
}