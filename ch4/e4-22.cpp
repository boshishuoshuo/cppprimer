#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string finalGrade;
    int grade;

    cout << "Please enter a grade: " << endl;

    if (cin >> grade && grade >= 0 && grade <= 100)
    {
        finalGrade = (grade < 60 ) ? "fail"
                                    : ( grade < 75 ) ? "low pass"
                                    : ( grade < 90 ) ? "pass" : "high pass" ;
    } else
    {
        cout << "wrong intput" << endl;
        return -1;
    }
    cout << "final grad is " << finalGrade << endl;

    cout << "Please enter another grade: " << endl;

    if (cin >> grade && grade >= 0 && grade <= 100)
    {
        if (grade < 60 ) finalGrade = "fail";
        else if (grade < 75) finalGrade = "low pass";
        else if (grade < 90) finalGrade = "pass";
        else finalGrade = "high pass";
    } else
    {
        cout << "wrong intput" << endl;
        return -1;
    }
    cout << "final grad is " << finalGrade << endl;

    return 0;
}
