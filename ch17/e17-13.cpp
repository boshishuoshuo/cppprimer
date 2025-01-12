#include <iostream>
#include <bitset>

using namespace std;

template <size_t N>
class exam 
{
    public:
        exam(int x): s(x) {}
        size_t get_size() { return N; }
        void set_solution(size_t n, bool b)
            { s.set(n, b);}
        bitset<N> get_solution() const
            { return s; }
        size_t score(const bitset<N> &a);

    private:
        bitset<N> s;
};

template <size_t N>
size_t exam<N>::score(const bitset<N> &a)
{
    size_t ret = 0;
    for (size_t i = 0; i < N; i++)
        if (s[i] == a[i])
            ret++;
    return ret;
}

int main(int argc, char const *argv[])
{
    exam<80> e(12345);

    cout << e.get_solution() << endl;
    bitset<80> a(345);
    cout << a << endl;

    cout << e.score(a) << endl;
    return 0;
}
