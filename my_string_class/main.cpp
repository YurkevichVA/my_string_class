#include <iostream>

#include "MyStr.h"

using namespace std;

int main()
{
    MyStr str("Hello");

    cout << str.getLength() << endl;
    cout << str.getSt() << endl;

    cout << endl;

    cout << boolalpha << str.findSubStr("as") << endl;
    cout << boolalpha << str.findSubStr("llo") << endl;

    cout << endl;

    cout << str.charSearch('l') << endl;
    cout << str.charSearch('a') << endl;

    cout << endl;

    str.printCounter();

    cout << endl;

    //str.inputStr();
    
    cout << endl;

    //str.printStr();

    cout << endl;

    MyStr str2(", C++!");

    str = str + str2;
    str.printStr();

    cout << endl;

    str.charDel('l');
    str.printStr();

    cout << str.myCmp(str2) << endl;
}