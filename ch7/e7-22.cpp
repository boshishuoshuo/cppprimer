#include <iostream>
#include <string>

using namespace std;

class Person 
{
    friend istream &read(istream &, Person &);
    friend ostream &print(ostream &, const Person &);
    private:
        string name;
        string address;
    public:
        Person() = default;
        Person(const string &namegiven, const string &addressgiven) {name = namegiven; address = addressgiven;}
        //Person(istream &is) {is >> *this;}
    public:
        string getName() const {return name;}
        string getAddress() const {return address;}
};

istream &read(istream &is, Person &per)
{
    is >> per.name >> per.address ;
    return is;
}

ostream &print(ostream &os, const Person &per)
{
    os << per.name << per.address << endl;
    return os;
}