#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <string>
#include "Sales_data.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream ifs("sales_data");
    istream_iterator<Sales_data> isit(ifs), eof;
    vector<Sales_data> vec_Sales_data(isit, eof);
    sort(vec_Sales_data.begin(), vec_Sales_data.end(), compareIsbn);
    auto l = vec_Sales_data.begin();
    while (l != vec_Sales_data.end())
    {
        auto item = *l;
        auto r = find_if(l+1, vec_Sales_data.end(), 
            [item](const Sales_data & s) { return s.isbn() != item.isbn();});
        auto sumItem = accumulate(l+1, r, item);
        cout << sumItem << endl;
        l = r;
    }

    return 0;
}
