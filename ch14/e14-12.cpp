#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
    public:
        friend ostream & operator<<(ostream &, Date &);
        friend istream & operator>>(istream &, Date &);
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

istream &operator>>(istream &is, Date &d)
{
    is >> d.year >> d.month >> d.day;
    if (!is) d = Date(0, 0, 0);
    return is;
}

int main(int argc, char const *argv[])
{
    string s("2023 3 28");
    istringstream iss(s);
    Date d;
    iss >> d;
    cout << d << endl;
    s = "abc";
    istringstream iss1(s);
    iss1 >> d;
    cout << d << endl;

    return 0;
}
