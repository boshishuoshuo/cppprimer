#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    istringstream iss("hello world my dear my zoe my mia");
    set<string> stringset;
    string word;
    while (iss >> word)
    {
        stringset.insert(word);
    }
    ostream_iterator<string> oit(cout, " ");
    copy(stringset.begin(), stringset.end(), oit);
    cout << endl;
    return 0;
}
