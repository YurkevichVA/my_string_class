#include <iostream>

#include "MyStr.h"

using namespace std;

int main()
{
    str n_str_1("Hello, "), n_str_2("my string class");
    str res;
    res = n_str_1 + n_str_2;
    res.print();
}