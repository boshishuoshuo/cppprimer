#include <iostream>
#include <string>

using namespace std;

template <int H, int W> class Screen;

template <int H, int W> 
istream& operator>>(istream &, Screen<H, W> &);

template <int H, int W> 
ostream& operator<<(ostream &, Screen<H, W> &);

template <int H, int W>
class Screen
{
    friend ostream& operator<<<H, W>(ostream &, Screen<H, W> &);
    friend istream& operator>><H, W>(istream &, Screen<H, W> &);
    public:
        typedef string::size_type pos;
        Screen() : content(H * W, ' ') {};
        Screen(char c) : content(H * W, c) {};
        char get() const
            { return content[cursor]; }
        inline char get(pos r, pos c) const
        {
            int row = r * W;
            return content[row + c];
        }
        Screen & clear(char = bkground);
    public:
        Screen& move(unsigned r, unsigned c)
        {
            int row = r * W;
            cursor = row + c;
            return *this;
        }

        Screen& set(char ch)
        {
            content[cursor] = ch;
            return *this;
        }

        Screen& set(unsigned r, unsigned c, char ch)
        {
            content[r * W + c] = ch;
            return *this;
        }
        Screen& display(ostream &os)
        {
            do_display(os); 
            return *this;
        }

        const Screen& display(ostream &os) const 
        {
            do_display(os); 
            return *this;
        }

    private:
        void do_display(ostream &os) const
            { os << content; }
        pos cursor = 0;
        string content;
        static const char bkground = ' ';
};

template <int H, int W>
Screen<H, W> &Screen<H, W>::clear(char c)
{
    content = string(H*W, c);
    return *this;
}
template <int H, int W>
istream& operator>>(istream &is, Screen<H, W> & s)
{
    string t;
    is >> t;
    s.content = t.substr(0, H*W);
    return is;
}

template <int H, int W>
ostream& operator<<(ostream & os, Screen<H, W> & s)
{
    os << s.content;
    return os;
}

int main(int argc, char const *argv[])
{
    Screen<5, 3> myScreen;
    myScreen.display(cout);
    cout << endl;
    myScreen.move(4, 0).set('#');
    Screen<5, 5> nextScreen('X');
    nextScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    const Screen<5, 3> blank;
    myScreen.set('#').display(cout);
    cout << endl;
    blank.display(cout);
    cout << endl;
    myScreen.clear('Z').display(cout);
    cout << endl;
    myScreen.move(4, 0);
    myScreen.set('#');
    myScreen.display(cout);
    cout << endl;
    myScreen.clear('Z').display(cout);
    cout << endl;
    Screen<5, 3> temp = myScreen.move(4, 0);
    temp.set('#');
    myScreen.display(cout);
    cout << endl;

    cin >> myScreen;
    cout << myScreen << endl << nextScreen << endl << temp << endl;

    return 0;
}
