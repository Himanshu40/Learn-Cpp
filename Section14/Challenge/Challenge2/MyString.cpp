#include <cstring>
#include "MyString.h"


MyString::MyString() : MyString {nullptr} {
    std::cout << "No-Args constructor called" << std::endl;
}

MyString::MyString(const char *s) : str {nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
        std::cout << "Parameterized constructor called for nullptr" << std::endl;
    }
    else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
        std::cout << "Parameterized constructor called for " << str << std::endl;
    }
}

MyString::MyString(const MyString &src) : MyString {src.str} {
    std::cout << "Deep copy constructor called for " << src.str << std::endl;
}

MyString::MyString(MyString &&src) noexcept : str {src.str} {
    std::cout << "Parameterized constructor called for " << src.str << std::endl;
    src.str = nullptr;
}

MyString::~MyString() {
    if (str == nullptr) {
        std::cout << "Destructor called for nullptr" << std::endl;
    }
    else {
        std::cout << "Destructor called for " << str << std::endl;
    }

    delete [] str;
}


MyString &MyString::operator=(const MyString &rhs) {
    std::cout << "Copy assignment called for " << rhs.str << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

MyString &MyString::operator=(MyString &&rhs) noexcept {
    std::cout << "Move assignment called for " << rhs.str << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

void MyString::display() const {
    std::cout << str << std::endl;
}