#include <iostream>
#include <string>

using namespace std;

void update_name(string &name, const string &prefix, const string &suffix)
{
    name.insert(name.begin(), ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" ");
    name.append(suffix);
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
