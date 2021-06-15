#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <iostream>

class MyString {
        // Pointer to char[] that hold a C-Style String
        char *str;

        friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
        friend std::istream &operator>>(std::istream &in, MyString &rhs);
    public:
        MyString();
        MyString(const char *s);
        MyString(const MyString &src);
        MyString(MyString &&src) noexcept;
        ~MyString();

        // Copy assignment
        MyString &operator=(const MyString &rhs);
        // Move assignment
        MyString &operator=(MyString &&rhs);

        void display() const;
        int getLength() const;
        const char *getStr() const;
};


#endif
