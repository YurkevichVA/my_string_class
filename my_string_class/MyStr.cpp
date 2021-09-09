#include "MyStr.h"

#include <string>
#include <iostream>

using namespace std;

// def. ctor

MyStr::MyStr() 
{
    length = 80;
    st = new char[length];
}

// ctor with length param.

MyStr::MyStr(int length)
{
    this->length = length;
    st = new char[this->length];
}

// ctor with char* param.

MyStr::MyStr(const char* n_st)
{
    if (this->st != nullptr)
    {
        delete[] this->st;
        this->st = nullptr;
    }

    length = strlen(n_st) + 1;
    st = new char[length];
    for (int i = 0; i < length; i++)
    {
        st[i] = n_st[i];
    }
    st[length] = '\0';
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

    this->st[length] = '\0';
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

    this->st[length] = '\0';

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

    this->st[length] = '\0';

    return *this;
}

// concat

MyStr MyStr::operator+(const MyStr& c_str)
{
    MyStr n_str;
    n_str.length = this->length + c_str.length;
    n_str.st = new char[length];

    int i = 0;

    for (; i < this->length; i++)
    {
        n_str.st[i] = this->st[i];
    }
    for (int j = 0; i < length; i++, j++)
    {
        n_str.st[i] = c_str.st[j];
    }

    n_str.st[length] = '\0';

    return n_str;
}

// print method

void MyStr::print()
{
    for (int i = 0; i < length; i++)
    {
        cout << st[i];
    }
}

MyStr::~MyStr()
{
    if (st != nullptr)delete[] st;
}