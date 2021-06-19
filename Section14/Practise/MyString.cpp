#include "MyString.h"
#include <cstring>


std::ostream &operator<<(std::ostream &os, const MyString &rhs) {
    os << rhs.str;

    return os;
}

std::istream &operator>>(std::istream &is, MyString &rhs) {
    char *buff = new char[100];
    
    is >> buff;
    rhs = MyString {buff};
    delete [] buff;

    return is;
}


MyString::MyString() : MyString {nullptr} {
    std::cout << "No-Args constructor called" << std::endl;
}

MyString::MyString(const char *s) : str {nullptr} {
    if (s == nullptr) {
        std::cout << "Parameterized constructor called for NULL" << std::endl;
        str = new char[1];
        *str = '\0';    
    }
    else {
        std::cout << "Parameterized constructor called for " << s << std::endl;
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

MyString::MyString(const MyString &src) : MyString {src.str} {
    std::cout << "Deep copy constructor called " << src.str << std::endl;
}

MyString::MyString(MyString &&src) noexcept : str {src.str} {
    std::cout << "Move constructor called " << src.str << std::endl;
    src.str = nullptr;
}

MyString::~MyString() {
    if (str == nullptr) {
        std::cout << "Destructor called for MyString : nullptr " << std::endl;
    }
    else {
        std::cout << "Destructor called for MyString : " << str << std::endl;
    }
    
    delete [] str;
}


MyString &MyString::operator=(const MyString &rhs) {
    std::cout << "Deep Copy assignment called for " << str << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

MyString &MyString::operator=(MyString &&rhs) noexcept {
    std::cout << "Move assignment called for " << str << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}


MyString MyString::operator-() const {
    size_t buffSize = std::strlen(str) + 1;
    char *buff = new char[buffSize];

    std::strcpy(buff, str);

    for (size_t i {0}; i != buffSize; ++i) {
        buff[i] = std::tolower(buff[i]);
    }

    MyString temp {buff};
    delete [] buff;

    return temp;
}

MyString &MyString::operator++() {
    size_t strSize = std::strlen(str);

    for (size_t i {0}; i != strSize; ++i) {
        str[i] = std::toupper(str[i]);
    }

    return *this;
}

MyString MyString::operator++(int unused) {
    MyString temp {*this};

    operator++();

    return temp;
}

MyString MyString::operator+(const MyString &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];

    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);

    MyString temp {buff};
    delete [] buff;

    return temp;
}

MyString &MyString::operator+=(const MyString &rhs) {
    operator+(rhs);

    return *this;
}

MyString MyString::operator*(unsigned int times) const {
    MyString temp;

    for (unsigned int i {0}; i != times; ++i) {
        temp = temp + *this;
    }

    return temp;
}

MyString &MyString::operator*=(unsigned int times) {
    operator*(times);

    return *this;
}


bool MyString::operator==(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

bool MyString::operator!=(const MyString &rhs) const {
    return !(*this == rhs);
}

bool MyString::operator<(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

bool MyString::operator>(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}


void MyString::display() const {
    std::cout << str << std::endl;
}
