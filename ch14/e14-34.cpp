#include <iostream>

using namespace std;

class IfElseThen
{
    public:
        IfElseThen() {}
        IfElseThen(int v1, int v2, int v3): v1(v1), v2(v2), v3(v3) {}
        int operator()(int i1, int i2, int i3)
        {
            return i1 ? i2 : i3;
        }

    private:
        int v1, v2, v3;
};

int main(int argc, char const *argv[])
{
    IfElseThen obj;
    cout << obj(1, 2, 3) << endl;
    cout << obj(0, 5, 6) << endl;
    return 0;
}
