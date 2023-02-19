#include <iostream>
#include <string>

using namespace std;

class Window_mgr
{
    public:
        void clear();
};

class Screen
{
    friend void Window_mgr::clear();
    private:
        unsigned height = 0, width = 0;
        unsigned cursor = 0;
        string content;
    public:
        Screen() = default;
        Screen(unsigned ht, unsigned wd) : height(ht), width(wd), content(ht * wd, ' ') {}
        Screen(unsigned ht, unsigned wd, char c) : height(ht), width(wd), content(ht * wd, c) {}
    public:
        Screen& move(unsigned r, unsigned c)
        {
            cursor = r * width + c;
            return *this;
        }

        Screen& set(char ch)
        {
            content[cursor] = ch;
            return *this;
        }

        Screen& set(unsigned r, unsigned c, char ch)
        {
            content[r * width + c] = ch;
            return *this;
        }
        Screen& display(ostream &os)
        {
            for (int i = 0; i < width ; ++i)
            {
                os << content.substr(i * width, width) << endl;
            }
            return *this;
        }
};

void Window_mgr::clear()
{
    Screen myScreen(10, 20, 'X');
    cout << "before clean up" << endl;
    cout << myScreen.content << endl;
    myScreen.content = "";
    cout << "after clean up" << endl;
    cout << myScreen.content << endl;
}

int main(int argc, char const *argv[])
{
    Window_mgr w;
    w.clear();
    return 0;
}
