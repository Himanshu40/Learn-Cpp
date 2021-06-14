#ifndef _MY_STRING_H_
#define _MY_STRING_H_


class MyString {
        // Pointer to char[] that hold a C-Style String
        char *str;
    public:
        MyString();
        MyString(const char *s);
        MyString(const MyString &src);
        MyString(MyString &&src);
        ~MyString();

        // Copy assignment
        MyString &operator=(const MyString &rhs);
        // Move assignment
        MyString &operator=(MyString &&rhs);

        // Make lowercase string
        MyString operator-() const;
        // Concatenate string
        MyString operator+(const MyString &rhs) const;
        // Check if two strings are equal
        bool operator==(const MyString &rhs) const;

        void display() const;
        int getLength() const;
        const char *getStr() const;
};


#endif
