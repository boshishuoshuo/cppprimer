#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    friend istream& operator >> (istream&, Sales_data&);
    friend ostream& operator << (ostream&, const Sales_data&);
    friend bool operator < (const Sales_data&, const Sales_data&);
    friend bool operator == (const Sales_data&, const Sales_data&);

    public:
        Sales_data() = default;
        Sales_data(const string &book): bookNo(book) {}
        Sales_data(istream &is) {is >> *this;}
    public:
        Sales_data& operator += (const Sales_data&);
        string isbn() const {return bookNo;}
    private:
        string bookNo;
        unsigned units_sold = 0;
        double sellingprice = 0.0;
        double saleprice = 0.0;
        double discount = 0.0;

};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
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
    Sales_data book;
    cout << "Please enter sales data: " << endl;
    while (cin >> book) {
        cout << book << endl;
    }
    Sales_data trans1, trans2;
    cout << "Please enter 2 transactions with the same ISBN: " << endl;
    cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
        cout << trans1 + trans2 << endl;
    else   
        cout << "The 2 transactions are different" << endl;
    
    Sales_data total, trans;
    cout << "please enter some transaction with same ISBN: " << endl;
    if (cin >> total ) {
        while (cin >> trans) 
            if (compareIsbn(total, trans))
                total += trans;
            else {
                cout << "ISBN is different" << endl;
                break;
            }
        cout << total << endl;
    }
    else {
        cout << "No data" << endl;
        return -1;
    }

    int num = 1;
    cout << "Please enter transactions: " << endl;

    if (cin >> trans1) {
        while (cin >> trans2)
            if (compareIsbn(trans1, trans2))
                num++;
            else {
                cout << trans1.isbn() << " has " << num << " transactions " << endl;
                trans1 = trans2;
                num =1;
             }
        cout << trans1.isbn() << " has " << num << " transactions " << endl;
    }
    else {
        cout << "No data" << endl;
        return -1;
    }

    return 0;
}
