#include "MyStr.h"

#include <string>
#include <iostream>

using namespace std;

// static counter

int MyStr::countMyStrings = 0;

// method for output static counter

void MyStr::printCounter()const
{
    cout << countMyStrings << endl;
}

// def. ctor

MyStr::MyStr() 
{
    length = 80;

    if (st != nullptr)
    {
        delete[] st;
        st = nullptr;
    }

    st = new char[length];
    countMyStrings++;
}

// ctor with length param.

MyStr::MyStr(int length)
{
    this->length = length;

    if (st != nullptr)
    {
        delete[] this->st;
        st = nullptr;
    }

    st = new char[this->length];

    countMyStrings++;
}

// ctor with char* param.

MyStr::MyStr(const char* n_st)
{
    if (st != nullptr)
    {
        delete[] st;
        st = nullptr;
    }

    length = strlen(n_st) + 1;
    st = new char[length];

    for (int i = 0; i < length; i++)
    {
        st[i] = n_st[i];
    }

    countMyStrings++;
}

// copy ctor

MyStr::MyStr(const MyStr& other)
{
    if (this->st != nullptr)
    {
        delete[] this->st;
        this->st = nullptr;
    }

    length = other.getLength();
    this->st = new char[length];

    for (int i = 0; i < length; i++)
    {
        this->st[i] = other.st[i];
    }

    countMyStrings++;
}

// inspectors

const char* MyStr::getSt()const
{
    return st;
}

int MyStr::getLength()const
{
    return length;
}

// overwise oper. = for same type

MyStr& MyStr::operator=(const MyStr& other)
{
    if (this->st != nullptr)
    {
        delete[] this->st;
        this->st = nullptr;
    }

    length = other.getLength();
    this->st = new char[length];

    for (int i = 0; i < length; i++)
    {
        this->st[i] = other.st[i];
    }

    return *this;
}

// overwise oper. = for char*

MyStr& MyStr::operator=(const char* char_arr)
{
    if (this->st != nullptr)
    {
        delete[] this->st;
        this->st = nullptr;
    }

    length = strlen(char_arr) + 1;
    this->st = new char[length];

    for (int i = 0; i < length; i++)
    {
        this->st[i] = char_arr[i];
    }

    //this->st[length] = '\0';

    return *this;
}

// concat

MyStr MyStr::operator+(const MyStr& c_str)
{
    MyStr n_str(this->length + c_str.length - 1);

    int i = 0;

    for (; i < this->length - 1; i++)
    {
        n_str.st[i] = this->st[i];
    }
    for (int j = 0; i < n_str.length; i++, j++)
    {
        n_str.st[i] = c_str.st[j];
    }

    //n_str.st[length] = '\0';

    return n_str;
}

// print method

void MyStr::printStr()const
{
    for (int i = 0; i < length; i++)
    {
        cout << st[i];
    }
}

// input method

void MyStr::inputStr()
{
    if (this->st != nullptr)
    {
        delete[] this->st;
        this->st = nullptr;
    }

    cout << "Enter string length: ";
    cin >> length;

    st = new char[length];

    cin.ignore();

    cout << "Enter string: ";
    gets_s(st, length);
}

// character search

int MyStr::charSearch(char key)
{
    for (int i = 0; i < length; i++)
    {
        if (st[i] == key)return i;
    }
    return -1;
}

// search substr

bool MyStr::findSubStr(const char* sub_str)const
{
    for (int i = 0; i < this->length; i++)
    {
        for (int j = i, k = 0; k <= strlen(sub_str); j++, k++)
        {
            if (this->st[j] != sub_str[k]) break;
            if (this->st[j] == sub_str[k] && k == strlen(sub_str)) return true;
        }
    }
    return false;
}

// delete char

void MyStr::charDel(char del_char)
{
    MyStr buff(length - 1);
    int index = charSearch(del_char);
    //char* buff = new char[length - 1];
    for (int i = 0, j = 0; j < this->length; i++, j++)
    {
        if (j == index)j++;
        buff.st[i] = this->st[j];
    }

    delete[] this->st;
    this->st = nullptr;

    *this = buff;
}

// compare strings

int MyStr::myCmp(const MyStr& other)const
{
    for (int i = 0; i < this->length; i++)
    {
        if ((int)this->st[i] - (int)other.st[i] > 0)return -1;
        else if ((int)this->st[i] - (int)other.st[i] < 0)return 1;
    }
    return 0;
}

// destructor

MyStr::~MyStr()
{
    if (st != nullptr)delete[] st;

    countMyStrings--;
}