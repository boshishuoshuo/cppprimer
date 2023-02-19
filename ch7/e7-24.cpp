#include <iostream>
#include <string>

using namespace std;

class Screen
{
    private:
        unsigned height = 0, width = 0;
        unsigned cursor = 0;
        string content;
    public:
        Screen() = default;
        Screen(unsigned ht, unsigned wd) : height(ht), width(wd), content(ht * wd, ' ') {}
        Screen(unsigned ht, unsigned wd, char c) : height(ht), width(wd), content(ht * wd, c) {}
};