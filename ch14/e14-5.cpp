#include <iostream>

using namespace std;

class Date
{
    public:
        friend ostream & operator<<(ostream &, Date &);
    public:
        Date() {}
        Date(int y, int m, int d): year(y), month(m), day(d) {}
    private:
        int year, month, day;
};

ostream& operator<<(ostream &os, Date &d)
{
    char sep = '\t';
    os << "year: " << d.year << sep << "month: " << d.month
        << sep << "day: " << d.day ;
    return os;
}

int main(int argc, char const *argv[])
{
    Date today(2023, 3, 28);
    cout << today << endl;
    return 0;
}
