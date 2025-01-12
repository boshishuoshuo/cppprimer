#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

inline void printout(list<string> & words)
{
    cout << words.size() << endl;
    for (auto it = words.begin(); it != words.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void elimDups(list<string> & words)
{
    printout(words);
    words.sort();
    printout(words);
    words.unique();
    printout(words);
}

int main(int argc, char const *argv[])
{
    list<string> words = {"hello", "world", "my", "dear", "my", "zoe", "my", "mia"};
    elimDups(words);
    return 0;
}
