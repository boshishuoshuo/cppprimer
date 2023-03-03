#include <iostream>
#include <string>

using namespace std;

void update_name(string &name, const string &prefix, const string &suffix)
{
    name.insert(0, " ");
    name.insert(0, prefix);
    name.insert(name.size(), " ");
    name.insert(name.size(), suffix);
}

int main(int argc, char const *argv[])
{
    string s = "James Bond";
    update_name(s, "Mr.", "II");
    cout << s << endl;

    s = "M";
    update_name(s, "Mrs.", "III");
    cout << s << endl;
    
    return 0;
}
