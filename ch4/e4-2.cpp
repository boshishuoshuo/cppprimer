#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec;
    srand((unsigned) time(NULL));
    for (int i = 0; i != 10; i++)
    {
        vec.push_back(rand() % 10);
    }
    for (auto e: vec)
        cout << e << " ";
    cout << endl;

    cout << "*vec.begin() : " << *vec.begin() << endl;
    cout << "*(vec.begin()) : " << *(vec.begin()) << endl;
    cout << "*vec.begin() + 1 : " << *vec.begin()  + 1 << endl;
    cout << "(*(vec.begin())) + 1 : " << *vec.begin() + 1 << endl;
        
    return 0;
}
