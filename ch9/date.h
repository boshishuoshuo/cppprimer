#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class date {
    public:
        friend ostream & operator<<(ostream &, const date &);

        date() = default;
        date(string &ds);

        unsigned y() const {return year;}
        unsigned m() const {return month;}
        unsigned d() const {return day;}

    private:
        unsigned year, month, day;
};

const string month_name[] = {"January", "February", "March",
            "April", "May", "June", "July", "August", "September",
            "October", "November", "December"};

const string month_abbr[] = {"Jan", "Feb", "Mar", "Apr", "May",
            "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int get_month(string &ds, int &end_of_month)
{
    int i, j;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < month_abbr[i].size(); j++)
            if(ds[j] != month_abbr[i][j])
                break;
            if (j == month_abbr[i].size())
                break;
    }

    if (i == 12)
        throw invalid_argument("not a valid month");
    
    if (ds[j] == ' ')
    {
        end_of_month = j + 1;
        return i + 1;
    }

    for (; j < month_name[i].size(); j++)
        if (ds[j] != month_name[i][j])
            break;
    
    if (j == month_name[i].size() && ds[j] == ' ')
    {
        end_of_month = j + 1;
        return i + 1;
    }

    throw invalid_argument("not a valid month");
}

inline int get_day(string &ds, int month, int &p)
{
    size_t q;
    int day = stoi(ds.substr(p), &q);
    if (day < 1 || day > days[month])
        throw invalid_argument("not a valid day");
    p += q;
    return day;
}

inline int get_year(string &ds, int &p)
{
    size_t q;
    int year = stoi(ds.substr(p), &q);
    if (p + q < ds.size())
        throw invalid_argument("not a valid ending");
    return year;
}

date::date(string &ds)
{
    int p;
    size_t q;
    if ((p = ds.find_first_of("0123456789")) == string::npos)
        throw invalid_argument("no digit, invalid date");
    if (p > 0)
    {
        month = get_month(ds, p);
        day = get_day(ds, month, p);
        if (ds[p] != ' ' && ds[p] != ',')
            throw invalid_argument("not a valid separator");
        p++;
        year = get_year(ds, p);
    } else
    {
        month = stoi(ds, &q);
        p = q;
        if (month < 1 || month > 12)
            throw  invalid_argument("not a valid month");
        if (ds[p++] != '/')
            throw invalid_argument("not a valid separator");
        day = get_day(ds, month, p);
        if (ds[p++] != '/')
            throw invalid_argument("not a valid separator");
        year = get_year(ds, p);
    }
}

ostream & operator<< (ostream & out, const date& d)
{
    cout << d.y() << " year " << d.m() << " month " << d.d() << " day " << endl;
    return out;
}

#endif