#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    list<string> lStr = {"hello", "world", "my", "dear", "mia", "zoe", "hello", "my", "my"};
    int c1, c2; 
    c1 = count(lStr.begin(), lStr.end(), "hello");
    c2 = count(lStr.begin(), lStr.end(), "my");
    cout << "hello occurs " << c1 << " times" << endl;
    cout << "my occurs " << c2 << " times" << endl;

    return 0;
}
