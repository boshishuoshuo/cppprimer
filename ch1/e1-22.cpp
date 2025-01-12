#include "Sales_item.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Sales_item transSum, trans1;
    if (cin >> transSum) {
        while (cin >> trans1) {
            if (compareIsbn(transSum, trans1)) {
                transSum += trans1;
            } else {
                cout << " isbn not the same " << endl;
                return -1;
            }
        }
        cout << transSum << endl;
    } else {
        cout << "no data" << endl;
        return -1;
    }

    return 0;
}
