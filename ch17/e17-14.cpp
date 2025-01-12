#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    try {
        regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);

    } catch (regex_error e)
    {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
    return 0;
}
