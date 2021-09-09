#pragma once

class MyStr
{
    char* st = nullptr;
    int length = 0;
public:
    // def. ctor
    MyStr();
    // ctor with length param.
    MyStr(int length);
    // ctor with char* param.
    MyStr(const char* n_st);
    // copy ctor
    MyStr(const MyStr& other);
    // inspectors
    const char* getSt()const;
    int getLength()const;
    // overwise oper. = for same type
    MyStr& operator=(const MyStr& other);
    // overwise oper. = for char*
    MyStr& operator=(const char* char_arr);
    // concat
    MyStr operator+(const MyStr& c_str);
    // print method
    void print();
    // destructor
    ~MyStr();
};

