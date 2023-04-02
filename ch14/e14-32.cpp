#include <string>

#include "my_StrBlob.h"

using namespace std;

class MyClass
{
    public:
        string * operator->()
        {
            return ptr->operator->();
        }
    private:
        StrBlobPtr *ptr;
};