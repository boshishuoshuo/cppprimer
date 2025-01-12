#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
    public:
        friend ostream & operator<<(ostream &, Date &);
        friend istream & operator>>(istream &, Date &);
        friend bool operator==(const Date &, const Date&);
        friend bool operator!=(const Date &, const Date&);
        friend bool operator<(const Date &, const Date&);
        friend bool operator<=(const Date &, const Date&);
        friend bool operator>(const Date &, const Date&);
        friend bool operator>=(const Date &, const Date&);
    public:
        Date() {}
        Date(int y, int m, int d): year(y), month(m), day(d) {}
        Date& operator=(const string );
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

bool operator==(const Date & d1, const Date &d2)
{
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator!=(const Date & d1, const Date &d2)
{
    return !(d1 == d2);
}

bool operator<(const Date &d1, const Date&d2)
{
    if (d2.year >= d1.year)
        return false;
    else if (d2.month >= d1.month)
        return false;
    else if (d2.day >= d1.day)
        return false;
    
    return true;
}

bool operator>(const Date &d1, const Date&d2)
{
    if (d2.year <= d1.year)
        return false;
    else if (d2.month <= d1.month)
        return false;
    else if (d2.day <= d1.day)
        return false;
    
    return true;
}

bool operator<=(const Date &d1, const Date&d2)
{
    return (d1 < d2) || (d1 == d2);
}

bool operator>=(const Date &d1, const Date&d2)
{
    return (d1 > d2) || (d1 == d2);
}

Date& Date::operator=(const string date)
{
    istringstream in(date);
    char ch1, ch2;
    in >> year >> ch1 >> month >> ch2 >> day;
    if (!in || ch1 != '-' || ch2 != '-')
        throw invalid_argument("Bad Date");
    if (month < 1 || month > 12 || day < 1 || day > 31)
        throw invalid_argument("Bad Date");
    return *this;
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

    const string s2("1982-10-28");
    Date d2;
    d2 = s2;
    cout << d2 << endl;

    return 0;
}
