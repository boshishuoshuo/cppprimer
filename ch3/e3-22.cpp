#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string text, line;
    vector<string> vText;
    
    text = "abc\ndef\nghi\n";
    stringstream ss(text);
    while (getline(ss, line))
    {
        vText.push_back(line);
    }

    for (auto it = vText.begin(); it != vText.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
            *it2 = toupper(*it2);
        cout << *it << endl;
    }
    return 0;
}
