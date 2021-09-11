#pragma once

class MyStr
{
    static int countMyStrings;
    char* st = nullptr;
    int length = 0;
public:
    // method for output static counter
    void printCounter()const;
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
    void printStr()const;
    // input method;
    void inputStr();
    // character search
    int charSearch(char key);
    // search substr
    bool findSubStr(const char* sub_str)const;
    // delete char
    void charDel(char del_ch);
    // compare strings
    int myCmp(const MyStr& other)const;
    // destructor
    ~MyStr();
};

