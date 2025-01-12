#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    char str1[] = "Hello ";
    char str2[] = "world";
    char result[strlen(str1) + strlen(str2)];
    cout << strlen(str1) << endl;
    cout << strlen(str2) << endl;
    cout << strlen(result) << endl;
    strcpy(result, str1);
    strcat(result, str2);
    cout << strlen(result) << endl;
    cout << result << endl;
    return 0;
}
