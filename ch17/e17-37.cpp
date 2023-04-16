#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in("storyDataFile");
    char text[50];
    while (!in.eof())
    {
        in.getline(text, 30);
        cout << text;
        //cout << in.gcount() << endl;
        //cout << in.good() << endl;
        if (!in.good())
        {
            if (in.gcount() == 29)
                in.clear();
            else
                break;
        } else
         cout << endl;
    }
    cout << endl;
    return 0;
}
