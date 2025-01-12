#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char const *argv[])
{
    bitset<32> bv1;
    bv1.set(1);
    bv1.set(2);
    bv1.set(3);
    bv1.set(5);
    bv1.set(8);
    bv1.set(13);
    bv1.set(21);
    cout << bv1 << endl;

    unsigned bp = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5 ) | (1 << 8)
                    | ( 1 << 13 ) | ( 1 << 21);
    bitset<32> bv(bp);
    cout << bv << endl;

    bitset<64> bitvec(32);
    cout << bitvec << endl;

    bitset<32> bv2("1010101");
    cout << bv2 << endl;

    return 0;
}
