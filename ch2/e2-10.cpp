#include <iostream>
#include <string>

using namespace std;

string global_str;
int global_int;

int main(int argc, char const *argv[])
{
    int local_int;
    string local_str;

    cout << global_str << endl;
    cout << global_int << endl;
    cout << local_int << endl;
    cout << local_str << endl;

    return 0;
}
