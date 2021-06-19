#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <iostream>


class MyString {
    private:
        char *str;
    public:
        MyString();
        MyString(const char *s);
        MyString(const MyString &src);
        MyString(MyString &&src) noexcept;
        ~MyString();

        MyString &operator=(const MyString &rhs);
        MyString &operator=(MyString &&rhs) noexcept;

        MyString operator-() const;
        MyString &operator++();
        MyString operator++(int unused);
        MyString operator+(const MyString &rhs) const;
        MyString &operator+=(const MyString &rhs);
        MyString operator*(unsigned int times) const;
        MyString &operator*=(unsigned int times);

        void display() const;
};

#endif