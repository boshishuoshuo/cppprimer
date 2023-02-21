#include <iostream>
#include <fstream>

#include "Sales_data.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
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
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }
    else
    {
        cerr << "No data" << endl;
        return -1;
    }
    return 0;
}
