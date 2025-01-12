#ifndef SALES_DATA_H_INCLUDED
#define SALES DATA_H_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class out_of_stock: public runtime_error
{
    public:
        explicit out_of_stock(const string&s):
                    runtime_error(s) {}
};

class isbn_mismatch: public logic_error
{
    public:
        explicit isbn_mismatch(const string&s):
                    logic_error(s) {}
        isbn_mismatch(const string &s,
                        const string &lhs, const string &rhs):
                        logic_error(s), left(lhs), right(rhs) {}
        const string left, right;
};

class Sales_data {
    friend istream& operator >> (istream&, Sales_data&);
    friend ostream& operator << (ostream&, const Sales_data&);
    friend bool operator < (const Sales_data&, const Sales_data&);
    friend bool operator == (const Sales_data&, const Sales_data&);
    friend istream& read(istream&, Sales_data&);
    friend ostream& print(ostream&, const Sales_data&);
    friend Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

    public:
        Sales_data() = default;
        Sales_data(const string &book): bookNo(book) {}
        Sales_data(const string &book, const unsigned num, const double sellp, const double salep);
        Sales_data(istream &is) {is >> *this;}
        Sales_data & operator-=(const Sales_data &);
    public:
        Sales_data& operator += (const Sales_data&);
        Sales_data& operator=(const string &);
        string isbn() const {return bookNo;}
    private:
        string bookNo;
        unsigned units_sold = 0;
        double sellingprice = 0.0;
        double saleprice = 0.0;
        double discount = 0.0;

};

Sales_data::Sales_data(const string &book, const unsigned num, const double sellp, const double salep)
{
    bookNo = book;
    units_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if (sellingprice != 0)
    {
        discount = saleprice / sellingprice ;
    }
}

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

inline bool operator == (const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.units_sold == rhs.units_sold &&
        lhs.sellingprice == rhs.sellingprice &&
        lhs.saleprice == rhs.saleprice &&
        lhs.isbn() == rhs.isbn();
}

inline bool operator != (const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

Sales_data& Sales_data::operator += (const Sales_data& rhs)
{
    if (isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice*rhs.units_sold + saleprice*units_sold) 
        / (rhs.units_sold + units_sold);
    if (sellingprice != 0) 
        discount = saleprice / sellingprice;
    return *this;
}

Sales_data operator + (const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}

Sales_data & Sales_data::operator-=(const Sales_data &rhs)
{
    if (isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    units_sold -= rhs.units_sold;
    return *this;

}

Sales_data& Sales_data::operator=(const string &isbn)
{
    bookNo = isbn;
    return *this;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sub = lhs;
    sub -= rhs;
    return sub;
}

istream& operator >> (istream& in, Sales_data& s)
{
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
        s.discount = s.saleprice / s.sellingprice;
    else 
        s = Sales_data();
    return in;
}

ostream& operator << (ostream& out, const Sales_data& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.sellingprice << " " << s.saleprice << " " << s.discount;
    return out;
}

bool operator< (const Sales_data& lhs, const Sales_data& rhs)
{
    return lhs.isbn() < rhs.isbn();
}

istream & read(istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    if (is && item.sellingprice != 0)
        item.discount = item.saleprice / item.sellingprice;
    else 
        item = Sales_data();
    return is;
}

ostream & print(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount << endl; 
    return os;
}

#endif