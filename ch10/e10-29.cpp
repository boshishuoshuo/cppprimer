#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in("sales_data");
    istream_iterator<string> in_iter(in), eof;
    vector<string> vStr(in_iter, eof);
    for (auto s: vStr)
        cout << s << endl;
    in.close();
    return 0;
}
