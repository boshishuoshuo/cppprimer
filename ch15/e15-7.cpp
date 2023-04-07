#include <iostream>
#include <string>

using namespace std;

class Quote
{
    public:
        Quote() = default;
        Quote(const string &book, double sales_price): bookNo(book), price(sales_price) {}
    
        string isbn() const { return bookNo;}
        virtual double net_price(size_t n) const
            {return n * price;}
    private:
        string bookNo;
    protected:
        double price = 0.0;
};

class Bulk_quote : public Quote
{
    public:
        Bulk_quote() = default;
        Bulk_quote(const string&, double, size_t, double);
        double net_price(size_t) const override;
    private:
        size_t min_qty = 0;
        double discount = 0.0;
};

Bulk_quote::Bulk_quote(const string& book, double p, 
                        size_t qty, double disc): Quote(book, p), 
                        min_qty(qty), discount(disc) {}

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1- discount) * price;
    else    
        return cnt * price;
}

class Limited_quote : public Quote
{
    public:
        Limited_quote() = default;
        Limited_quote(const string&, double, size_t, double);
        double net_price(size_t) const override;
    private:
        size_t max_qty = 0;
        double discount = 0.0;
};

Limited_quote::Limited_quote(const string &book, double p,
                        size_t qty, double disc) : Quote(book, p), 
                        max_qty(qty), discount(disc) {}

double Limited_quote::net_price(size_t n) const 
{
    if (n <= max_qty)
        return n * ( 1 - discount) * price;
    else   
        return (n - max_qty) * price + max_qty * (1 - discount) * price;
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
    print_total(cout, base_quote, 5);

    Bulk_quote bulk_quote("abc", 10.00, 10, 0.1);
    print_total(cout, bulk_quote, 15);

    Limited_quote limited_quote("abc", 10.00, 10, 0.1);
    print_total(cout, limited_quote, 15);

    return 0;
}
