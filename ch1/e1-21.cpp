#include "Sales_item.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Sales_item trans1, trans2;
    cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2)) 
        cout << trans1 + trans2 << endl;
    else 
        cout << "isbn not same " << endl;
    return 0;
}
