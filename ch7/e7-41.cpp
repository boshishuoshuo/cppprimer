#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    friend istream& operator >> (istream&, Sales_data&);
    friend ostream& operator << (ostream&, const Sales_data&);
    friend bool operator < (const Sales_data&, const Sales_data&);
    friend bool operator == (const Sales_data&, const Sales_data&);
    friend istream& read(istream&, Sales_data&);
    friend ostream& print(ostream&, const Sales_data&);

    public:
        Sales_data() : Sales_data("", 0, 0, 0) 
        {
            cout << "this constructor accepts no info" << endl;
        }
        Sales_data(const string &book): Sales_data(book, 0, 0, 0) 
        {
            cout << "This constructor accepts isbn" << endl;
        }
        Sales_data(const string &book, const unsigned num, const double sellp, const double salep);
        Sales_data(istream &is) : Sales_data() 
        {   
            is >> *this; 
            cout << "This constructor accepts user input" << endl;
        }
    public:
        Sales_data& operator += (const Sales_data&);
        Sales_data& combine(const Sales_data&);
        string isbn() const {return bookNo;}
        double avg_price() const 
        {
            if (units_sold)
                return revenue / units_sold;
            else
                return 0;
        }
    private:
        string bookNo;
        unsigned units_sold = 0;
        double sellingprice = 0.0;
        double saleprice = 0.0;
        double discount = 0.0;
        double revenue = 0.0;
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

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
    cout << "This constructor accepts isbn, amount, selling price, and sales price" << endl;
}

Sales_data operator + (const Sales_data&, const Sales_data&);

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
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice*rhs.units_sold + saleprice*units_sold) 
        / (rhs.units_sold + units_sold);
    if (sellingprice != 0) 
        discount = saleprice / sellingprice;
    return *this;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice*rhs.units_sold + saleprice*units_sold) 
        / (rhs.units_sold + units_sold);
    if (sellingprice != 0) 
        discount = saleprice / sellingprice;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    return sum.combine(rhs);
}

istream & read(istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    return is;
}

ostream & print(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount; 
    return os;
}

Sales_data operator + (const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
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

int main(int argc, char const *argv[])
{
    Sales_data data1("abc", 20, 10.0, 8.0);
    Sales_data data2;
    Sales_data data3("abd");
    Sales_data data4(cin);

    cout << data1 << endl;
    cout << data2 << endl;
    cout << data3 << endl;
    cout << data4 << endl;

    return 0;
}
