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

        MyString &operator=(const MyString &rhs);
        MyString &operator=(MyString &&rhs) noexcept;

        void display() const;
};

#endif