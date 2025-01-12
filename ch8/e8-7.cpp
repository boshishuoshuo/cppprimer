#include <iostream>
#include <fstream>

#include "Sales_data.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cerr << "Please enter file name." << endl;
        return -1;
    }

    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "can not open e8-1.cpp" << endl;
        return -1;
    }

    ofstream out;

    out.open(argv[2], ofstream::app);

    Sales_data total;
    if (read(in, total))
    {
        Sales_data trans;
        while (read(in, trans))
        {
            if (total.isbn() == trans.isbn())
                total += trans;
            else
            {
                out << total << endl;
                total = trans;
            }
        }
        out << total << endl;
    }
    else
    {
        cerr << "No data" << endl;
        return -1;
    }
    out.close();
    return 0;
}
