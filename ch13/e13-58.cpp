#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo
{
    public:
        Foo sorted() &&;
        Foo sorted() &;
    private:
        vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "right value reference" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() &
{
    cout << "left value reference" << endl;
    //Foo ret(*this);
    //sort(ret.data.begin(), ret.data.end());
    //return ret;
    
    //return ret.sorted();

    return Foo(*this).sorted();
}

int main(int argc, char const *argv[])
{
    Foo f;
    f.sorted();
    return 0;
}
