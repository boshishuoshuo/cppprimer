#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    string test_str = "receipt freind theif receive";
    for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it; 
            it != end_it; it++)
        cout << it->str() << endl;    
    return 0;
}
