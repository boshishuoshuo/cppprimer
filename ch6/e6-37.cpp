#include <string>

using namespace std;

typedef string stringarr10 [10];

stringarr10 &func1();

auto func2() -> string(&) [10];

string sa[10];

decltype(sa) &func3();

