#include <iostream>
#include <list>
#include <deque>

using namespace std;

bool isEven(int a)
{
    return a % 2 == 0;
}

int main(int argc, char const *argv[])
{
    list<int> iList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> oddDeque;
    deque<int> evenDeque;
    for (auto it = iList.begin(); it != iList.end(); ++it)
    {
        if (isEven(*it))
            evenDeque.push_back(*it);
        else
            oddDeque.push_back(*it);
    }

    cout << "printing odd numbers: " << endl;
    for (auto it = oddDeque.begin(); it != oddDeque.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "printing even numbers: " << endl;
    for (auto it = evenDeque.begin(); it != evenDeque.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
