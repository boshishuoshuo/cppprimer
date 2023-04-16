#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool get_status()
{
    return false;
}

int main(int argc, char const *argv[])
{
    bool b;
    cout << "default bool values: " << true << " " << false
        << "\nalpha bool values: " << boolalpha
        << true << " " << false << endl;
    
    bool bool_val = get_status();
    cout << boolalpha << bool_val
        << noboolalpha << endl;
    cout << endl;
    const int ival = 15, jval = 1024;
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "ocatal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;
    cout << endl;
    cout << showbase;
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "ocatal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;
    cout << noshowbase;
    cout << endl;

    cout << 10.0 << endl;
    cout << showpoint << 10.0 << noshowpoint << endl;

    cout << endl;
    cout << showpos << 10.0 << endl;
    cout << noshowpoint << 10.0 << endl;

    cout << endl;

    cout << uppercase << showbase << hex 
        << "printed in hexadecimal: " << 20 << " " << 1024
        << nouppercase << noshowbase << dec << endl;

    cout << endl;

    int i = -16;
    double d = 3.14159;
    cout << "i: " << setw(12) << i << " next col" << "\n"
        << "d: " << setw(12) << d << " next col" << "\n";
    cout << left
        << "i: " << setw(12) << i << " next col" << "\n"
        << "d: " << setw(12) << d << " next col" << "\n"
        << right;
    cout << right
        << "i: " << setw(12) << i << " next col" << "\n"
        << "d: " << setw(12) << d << " next col" << "\n";

    cout << internal
        << "i: " << setw(12) << i << " next col" << "\n"
        << "d: " << setw(12) << d << " next col" << "\n";
    cout << setfill('#')
        << "i: " << setw(12) << i << " next col" << "\n"
        << "d: " << setw(12) << d << " next col" << "\n"
        << setfill(' ');

    cout << endl;

    cout << unitbuf;
    cout << "default format: " << 100 * sqrt(2.0) << endl;
    cout << "scientific: " << scientific << 100 * sqrt(2.0) << endl;
    cout << "fixed decimal: " << fixed << 100 * sqrt(2.0) << endl;
    cout << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << endl;
    cout << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << endl;

    cout << nounitbuf;
    cout << endl;

    cout << "hi!" << endl;
    cout << "hi!" << ends << ends << ends;
    cout << "hi!" << ends;
    cout << "hi!" << ends;
    cout << "hi!" << ends;
    cout << "hi!" << flush;

    cout << endl;

    /* char ch;
    cin >> noskipws;
    while (cin >> ch)
        cout << ch;
    cin >> skipws; */
    return 0;
}
