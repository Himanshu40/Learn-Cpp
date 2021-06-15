#include <iostream>
#include <cstring>
#include "MyString.h"

// checks if two strings of both objects are equal or not
bool operator==(const MyString &lhs, const MyString &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Converts the string into lowercase
MyString operator-(const MyString &obj) {
    size_t buffSize = std::strlen(obj.str) + 1;
    char *buff = new char[buffSize];

    std::strcpy(buff, obj.str);

    for (size_t i {0}; i != buffSize; ++i) {
        buff[i] = std::tolower(buff[i]);
    }

    MyString temp {buff};
    delete [] buff;

    return temp;
}

// Concatenate two strings of both objects
MyString operator+(const MyString &lhs, const MyString &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];

    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);

    MyString temp {buff};
    delete [] buff;

    return temp;
}


MyString::MyString() : MyString {nullptr} {
}

MyString::MyString(const char *s) : str {nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

MyString::MyString(const MyString &src) : MyString {src.str} {
    std::cout << "Copy constructor used" << std::endl;
}

MyString::MyString(MyString &&src) noexcept : str {src.str} {
    src.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}

MyString::~MyString() {
    delete [] str;
}


MyString &MyString::operator=(const MyString &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

MyString &MyString::operator=(MyString &&rhs) {
    std::cout << "Using move assignment" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}


void MyString::display() const {
    std::cout << str << " : " << getLength() << std::endl;
}

int MyString::getLength() const {
    return std::strlen(str);
} 

const char *MyString::getStr() const {
    return str;
}
