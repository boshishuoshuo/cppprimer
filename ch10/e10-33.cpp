#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream ifs("number_input");
    istream_iterator<int> isit(ifs), eof;
    ofstream ofs_odd("odd_file"), ofs_even("even_file");
    ostream_iterator<int> ositodd(ofs_odd, " "), ositeven(ofs_even, "\n");
    while (isit != eof)
    {
        if (*isit & 1)
            *ositodd++ = *isit;
        else
            *ositeven++ = *isit;
        ++isit;
    }
    return 0;
}
