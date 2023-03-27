#include <iostream>

using namespace std;

class numbered
{
    private:
        static int seq;
    public:
        numbered() { mysn = seq++;}
        numbered(const numbered & num)
        {
            mysn = seq++;
        }
        numbered& operator=(const numbered &num)
        {
            mysn = seq++;
            return *this;
        }
        int mysn;
};

int numbered::seq = 0;
void f(const numbered &s)
{
    cout << s.mysn << endl;
}

int main(int argc, char const *argv[])
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    return 0;
}
