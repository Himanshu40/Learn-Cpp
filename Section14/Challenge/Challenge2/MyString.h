#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <iostream>

class MyString {
        char *str;
    public:
        MyString();
        MyString(const char *s);
        MyString(const MyString &src);
        MyString(MyString &&src) noexcept;
        ~MyString();

        void display() const;
};

#endif