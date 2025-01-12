#include "Sales_item.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Sales_item trans1, trans2;
    int num = 1;
    if (cin >> trans1) {
        while (cin >> trans2) {
            if (compareIsbn(trans1, trans2)) {
                num++;
            } else {
                cout << trans1.isbn() << " has " << num << " transactions" << endl;
                trans1 = trans2;
                num = 1;
            }
        }
        cout << trans1.isbn() << " has " << num << " transactions" << endl;
    } else {
        cout << "no sales data" << endl;
        return -1;
    }

    return 0;
}
