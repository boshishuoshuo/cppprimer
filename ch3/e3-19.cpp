#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T> 
void  printVectorsize(vector<T> &v)
{
    cout << v.size() << endl;
}

template <typename T> 
void printVectorContent(vector<T> &v)
{
    if (v.size() > 0)
    {
        for (auto it = v.cbegin(); it != v.cend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else 
    {
        cout << "empty" << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "v1 size is " ;
    printVectorsize<int>(v1);
    cout << "v2 size is " ;
    printVectorsize<int>(v2);
    cout << "v3 size is " ;
    printVectorsize<int>(v3);
    cout << "v4 size is " ;
    printVectorsize<int>(v4);
    cout << "v5 size is " ;
    printVectorsize<int>(v5);
    cout << "v6 size is " ;
    printVectorsize<string>(v6);
    cout << "v7 size is " ;
    printVectorsize<string>(v7);

    cout << "v1 content is " ;
    printVectorContent<int>(v1);
    cout << "v2 content is " ;
    printVectorContent<int>(v2);
    cout << "v3 content is " ;
    printVectorContent<int>(v3);
    cout << "v4 content is " ;
    printVectorContent<int>(v4);
    cout << "v5 content is " ;
    printVectorContent<int>(v5);
    cout << "v6 content is " ;
    printVectorContent<string>(v6);
    cout << "v7 content is " ;
    printVectorContent<string>(v7);

    return 0;
}
