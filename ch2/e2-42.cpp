#include <iostream>
#include "Sales_data.h"

int main(int argc, char const *argv[])
{
    Sales_data book;
    cout << "Please enter sales data: " << endl;
    while (cin >> book) {
        cout << book << endl;
    }
    Sales_data trans1, trans2;
    cout << "Please enter 2 transactions with the same ISBN: " << endl;
    cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
        cout << trans1 + trans2 << endl;
    else   
        cout << "The 2 transactions are different" << endl;
    
    Sales_data total, trans;
    cout << "please enter some transaction with same ISBN: " << endl;
    if (cin >> total ) {
        while (cin >> trans) 
            if (compareIsbn(total, trans))
                total += trans;
            else {
                cout << "ISBN is different" << endl;
                break;
            }
        cout << total << endl;
    }
    else {
        cout << "No data" << endl;
        return -1;
    }

    int num = 1;
    cout << "Please enter transactions: " << endl;

    if (cin >> trans1) {
        while (cin >> trans2)
            if (compareIsbn(trans1, trans2))
                num++;
            else {
                cout << trans1.isbn() << " has " << num << " transactions " << endl;
                trans1 = trans2;
                num =1;
             }
        cout << trans1.isbn() << " has " << num << " transactions " << endl;
    }
    else {
        cout << "No data" << endl;
        return -1;
    }

    return 0;
}