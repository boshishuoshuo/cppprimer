#include <iostream>
#include <string>

using namespace std;

class Quote
{
    public:
        Quote() = default;
        Quote(const string &book, double sales_price): bookNo(book), price(sales_price) 
        {
            cout << "Quote constructor is running" << endl;
        }
    
        string isbn() const { return bookNo;}
        virtual double net_price(size_t n) const
            {return n * price;}
        virtual void debug() const
        {
            cout << "bookNo: " << bookNo << " price : " << price << endl;
        }
        virtual ~Quote() 
        {
            cout << "Quote destructor is running" << endl;
        }
    private:
        string bookNo;
    protected:
        double price = 0.0;
};

ostream & operator << (ostream &os, Quote &e)
{
    os << "\t Using operator << (ostream &, Quote &); " << endl;
    return os;
}

class Bulk_quote : public Quote
{
    public:
        Bulk_quote(const string& book="", double sales_price=0.0, 
                    size_t qty = 0, double disc = 0.0):
                    Quote(book, sales_price), min_qty(qty), discount(disc)
        {
            cout << "Bulk_constructor is running" << endl;
        }
        double net_price(size_t) const override;
        virtual void debug() const override
        {
            Quote::debug();
            cout << "min_qty : " << min_qty << " discount : " << discount << endl;
        }
        ~Bulk_quote()
        {
            cout << "Bulk_quote desctructor is running " << endl;
        }
    private:
        size_t min_qty = 0;
        double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt > min_qty)
        return cnt * (1- discount) * price;
    else    
        return cnt * price;
}

ostream & operator << (ostream &os, Bulk_quote &bq)
{
    os << "\t Using operator << (ostream &, Bulk_quote &); " << endl;
    return os;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n
        << " total due: " << ret << endl;
    return ret;
}

int main(int argc, char const *argv[])
{
    Quote base_quote("abc", 10.0);

    Bulk_quote bulk_quote("abc", 10.00, 10, 0.1);

    cout << base_quote << endl;
    cout << bulk_quote << endl;
    return 0;
}
