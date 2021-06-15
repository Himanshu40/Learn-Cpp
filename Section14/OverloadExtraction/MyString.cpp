#include <cstring>
#include "MyString.h"


// Overloaded insertion operator as non-member function
std::ostream &operator<<(std::ostream &os, const MyString &rhs) {
    os << rhs.str;

    return os;
}

// Overloaded extraction operator as non-member function
std::istream &operator>>(std::istream &in, MyString &rhs) {
    char *buff = new char[1000];

    in >> buff;
    rhs = MyString {buff};

    delete [] buff;

    return in;
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
