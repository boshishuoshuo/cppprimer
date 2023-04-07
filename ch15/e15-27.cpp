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
        virtual void debug() const
        {
            cout << "bookNo: " << bookNo << " price : " << price << endl;
        }
        virtual ~Quote() = default;
    private:
        string bookNo;
    protected:
        double price = 0.0;
};

class Disc_quote : public Quote
{
    public:
        Disc_quote(const string &book = "", double price = 0.0, 
                    size_t qty = 0, double disc = 0.0) : 
                    Quote(book, price), quantity(qty), discount(disc) {}
        double net_price(size_t) const = 0;
    protected:
        size_t quantity = 0;
        double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
    public:
        using Disc_quote::Disc_quote;
        double net_price(size_t) const override;
        virtual void debug() const override
        {
            Quote::debug();
            cout << "min_qty : " << quantity << " discount : " << discount << endl;
        }
/*     private:
        size_t min_qty = 0;
        double discount = 0.0; */
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1- discount) * price;
    else    
        return cnt * price;
}

class Limited_quote : public Disc_quote
{
    public:
        using Disc_quote::Disc_quote;
        double net_price(size_t) const override;
        virtual void debug() const override;
/*     private:
        size_t max_qty = 0;
        double discount = 0.0; */
};

double Limited_quote::net_price(size_t n) const 
{
    if (n <= quantity)
        return n * ( 1 - discount) * price;
    else   
        return (n - quantity) * price + quantity * (1 - discount) * price;
}

void Limited_quote::debug() const
{
    Quote::debug();
    cout << "max_qty : " << quantity << " discount : " << discount << endl;

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
    base_quote.debug();

    Bulk_quote bulk_quote("abc", 10.00, 10, 0.1);
    print_total(cout, bulk_quote, 15);
    bulk_quote.debug();

    Limited_quote limited_quote("abc", 10.00, 10, 0.1);
    print_total(cout, limited_quote, 15);
    limited_quote.debug();

    //Disc_quote disc_quote("abc", 10.00, 10, 0.1);

    return 0;
}
