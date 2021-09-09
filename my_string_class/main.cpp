#include <iostream>

#include "MyStr.h"

using namespace std;

int main()
{
    MyStr n_str_1("Hello, "), n_str_2("my string class");
    MyStr res;
    res = n_str_1 + n_str_2;
    res.printStr();
}