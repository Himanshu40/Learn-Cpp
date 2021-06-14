#include <iostream>
#include <cstring>
#include <cctype>
#include "MyString.h"

// No-args constructor
MyString::MyString() 
    : MyString {nullptr} {
}

// Overloaded constructor
MyString::MyString(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
MyString::MyString(const MyString &src) 
    : MyString {src.str} {
        std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
MyString::MyString( MyString &&src) noexcept
    : str {src.str} {
        src.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// Destructor
MyString::~MyString() {
    delete [] str;
}

// Copy assignment operator
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

// Move assignment operator
MyString &MyString::operator=( MyString &&rhs) {
    std::cout << "Using move assignment" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

// Equality
bool MyString::operator==(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Make lowercase
MyString MyString::operator-() const {
    size_t buffSize = std::strlen(str) + 1;
    char *buff= new char[buffSize];

    std::strcpy(buff, str);
    
    for (size_t i = 0; i != buffSize; ++i) {
        buff[i] = std::tolower(buff[i]);
    }

    MyString temp {buff};
    delete [] buff;
    
    return temp;
}

// Concatentate two strings
MyString MyString::operator+(const MyString &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];

    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    
    MyString temp {buff};
    delete [] buff;
    
    return temp;
}

// Display method
void MyString::display() const {
    std::cout << str << " : " << getLength() << std::endl;
}

// length getter
int MyString::getLength() const { 
    return std::strlen(str); 
}
 
// string getter
const char *MyString::getStr() const { 
    return str; 
}
