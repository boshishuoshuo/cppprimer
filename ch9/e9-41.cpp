#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<char> vc = {'H', 'e', 'l', 'l', 'o'};
    auto p = vc.data();
    cout << p << endl;
    cout << *p << endl;

    char ca[] = "hello";
    cout << ca << endl;
    cout << *ca << endl;

    string s(vc.data(), vc.size());

    cout << s << endl;
    return 0;
}
