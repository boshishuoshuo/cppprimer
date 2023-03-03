#include <iostream>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    istringstream is("hello world my dear");
    string word;
    deque<string> ds;
    while (is >> word)
    {
        ds.push_back(word);
    }
    auto dsb = ds.begin();
    while (dsb != ds.end())
        cout << *dsb++ << endl;
    return 0;
}
