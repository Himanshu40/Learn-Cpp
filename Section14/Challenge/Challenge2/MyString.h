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

        friend MyString operator-(const MyString &obj);
        friend MyString &operator++(MyString &obj);
        friend MyString operator++(MyString &obj, int unused);
        friend MyString operator+(const MyString &lhs, const MyString &rhs);
        friend MyString &operator+=(MyString &lhs, const MyString &rhs);
        friend MyString operator*(const MyString &lhs, size_t times);
        friend MyString &operator*=(MyString &lhs, size_t times);

        friend bool operator==(const MyString &lhs, const MyString &rhs);
        friend bool operator!=(const MyString &lhs, const MyString &rhs);
        friend bool operator<(const MyString &lhs, const MyString &rhs);
        friend bool operator>(const MyString &lhs, const MyString &rhs);

        friend std::ostream &operator<<(std::ostream &os, const MyString &obj);
        friend std::istream &operator>>(std::istream &is, MyString &obj);

        void display() const;
};

#endif