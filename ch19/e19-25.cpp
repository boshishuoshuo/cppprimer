#include <iostream>

#include "Sales_data.h"

using namespace std;

class Token
{
    public:
        Token(): tok(INT), ival{0} {}
        Token(const Token &t): tok(t.tok) {copyUnion(t);}
        Token &operator=(const Token&);
        ~Token() 
        {
            if (tok == SDATA)
                sval.~Sales_data();
        }
        Token(Token &&other);
        Token &operator=(Token &&other);
        Token &operator=(char);
        Token &operator=(int);
        Token &operator=(double);
        Token &operator=(const Sales_data &);
    private:
        enum {INT, CHAR, DBL, SDATA } tok;
        union {
            char cval;
            int ival;
            double dval;
            Sales_data sval;
        };
        void copyUnion (const Token&);
};

Token &Token::operator=(int i)
{
    if (tok == SDATA) sval.~Sales_data();
    ival = i;
    tok = INT;
    return *this;
}

Token &Token::operator=(char c)
{
    if (tok == SDATA) sval.~Sales_data();
    cval = c;
    tok = CHAR;
    return *this;
}

Token &Token::operator=(double d)
{
    if (tok == SDATA) sval.~Sales_data();
    dval = d;
    tok = DBL;
    return *this;
}

Token &Token::operator=(const Sales_data &sd)
{
    if (tok == SDATA) 
        sval = sd;
    else
        new(&sval) Sales_data(sd);
    tok = SDATA;
    return *this;
}

void Token::copyUnion(const Token &t)
{
    switch (t.tok)
    {
    case Token::INT:
        ival = t.ival;
        break;
    case Token::CHAR:
        cval = t.cval;
        break;
    case Token::DBL:
        dval = t.dval;
        break;
    case Token::SDATA:
        new(&sval) Sales_data(t.sval);
        break;
    default:
        break;
    }
}

Token &Token::operator=(const Token &t)
{
    if (tok == SDATA && t.tok != SDATA)
        sval.~Sales_data();
    if (tok == SDATA && t.tok == SDATA)
        sval = t.sval;
    else
        copyUnion(t);
    tok = t.tok;
    return *this;
}

Token::Token(Token &&other): tok(INT), ival(0)
{
    tok = other.tok;
    ival = other.ival;
    other.tok = INT;
    other.ival = 0;
}

Token  & Token::operator=(Token &&other)
{
    if (this != &other)
    {
        //delete tok;
        tok = other.tok;
        ival = other.ival;
        other.tok = INT;
        other.ival = 0;
    }
    return *this;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
