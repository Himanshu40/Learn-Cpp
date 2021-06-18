#include "MyString.h"
#include <cstring>


MyString::MyString() : MyString {nullptr} {
    std::cout << "No-Args constructor called" << std::endl;
}

MyString::MyString(const char *s) : str {nullptr} {
    std::cout << "Parameterized constructor called for " << s << std::endl;

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
    std::cout << "Deep copy constructor called " << *src.str << std::endl;
}

MyString::MyString(MyString &&src) noexcept : str {src.str} {
    std::cout << "Move constructor called " << *src.str << std::endl;
    src.str = nullptr;
}

MyString::~MyString() {
    std::cout << "Destructor called for " << str << std::endl;
    
    delete [] str;
}


void MyString::display() const {
    std::cout << str << std::endl;
}