#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <iostream>


class MyString {
        char *str;
        friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
        friend std::istream &operator>>(std::istream &in, MyString &rhs);
    public:
        MyString();
        MyString(const char *s);
        MyString(const MyString &src);
        MyString(MyString &&src) noexcept;
        ~MyString();

        MyString &operator=(const MyString &rhs);
        MyString &operator=(MyString &&rhs);

        MyString operator-() const;
        MyString &operator++();
        MyString operator++(int unused);
        MyString operator+(const MyString &rhs) const;
        MyString &operator+=(const MyString &rhs);
        MyString operator*(size_t n) const;
        MyString &operator*=(size_t n);

        bool operator==(const MyString &rhs) const;
        bool operator!=(const MyString &rhs) const;
        bool operator<(const MyString &rhs) const;
        bool operator>(const MyString &rhs) const;
};


#endif
