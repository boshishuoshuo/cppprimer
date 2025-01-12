#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C>
void  print(const C &c)
{
    for (typename C::size_type i = 0; 
                i != c.size(); i ++)
    {
        cout << c.at(i) << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    string s = "hello world";
    print(s);

    vector<int> vi = { 0, 2, 4, 5, 7};
    print(vi);
    return 0;
}
