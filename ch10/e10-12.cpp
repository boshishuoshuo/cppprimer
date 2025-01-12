#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

void printVec(vector<Sales_data> & v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        print(cout, *it);
}

int main(int argc, char const *argv[])
{
    ifstream ifs("sales_data");
    if (!ifs)
    {
        cout << "open sales_data failed" << endl;
        exit(1);
    }

    vector<Sales_data> vSd;
    Sales_data sd;
    while (read(ifs, sd))
    {
        vSd.push_back(sd);
    }

    printVec(vSd);

    sort(vSd.begin(), vSd.end(), compareIsbn);

    cout << "After sorting..." << endl;
    printVec(vSd);


    return 0;
}
