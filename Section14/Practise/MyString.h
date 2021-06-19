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

        friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
        friend std::istream &operator>>(std::istream &is, MyString &rhs);

        MyString operator-() const;
        MyString &operator++();
        MyString operator++(int unused);
        MyString operator+(const MyString &rhs) const;
        MyString &operator+=(const MyString &rhs);
        MyString operator*(unsigned int times) const;
        MyString &operator*=(unsigned int times);

        bool operator==(const MyString &rhs) const;
        bool operator!=(const MyString &rhs) const;
        bool operator<(const MyString &rhs) const;
        bool operator>(const MyString &rhs) const;

        void display() const;
};

#endif
