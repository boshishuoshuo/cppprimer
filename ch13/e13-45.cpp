#include <iostream>
#include <vector>
#include <memory>

#include "String.h"

using namespace std;

int main(int argc, char const *argv[])
{
    String s1("One"), s2("Two");
    cout << s1 << " " << s2 << endl;
    String s3(s2);
    cout << s1 << " " << s2 << " " << s3 << endl;
    s3 = s1;
    cout << s1 << " " << s2 << " " << s3 << endl;
    s3 = String("Three");
    cout << s1 << " " << s2 << " " << s3 << endl;

    cout << endl;
    vector<String> vs;
    vs.reserve(4);
    vs.push_back(s1);
    vs.push_back(std::move(s2));
    vs.push_back(String("Three"));
    vs.push_back("Four");
    cout << endl;
    for_each(vs.begin(), vs.end(), [](const String &s) {cout << s << " ";});
    cout << endl;
    return 0;
}
