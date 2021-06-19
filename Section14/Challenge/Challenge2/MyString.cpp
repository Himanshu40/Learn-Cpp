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


MyString operator-(const MyString &obj) {
    size_t buffSize = std::strlen(obj.str);
    char *buff = new char[buffSize + 1];

    for (size_t i {0}; i != buffSize; ++i) {
        buff[i] = std::tolower(obj.str[i]);
    }

    MyString temp {buff};
    delete [] buff;

    return temp;
}

MyString &operator++(MyString &obj) {
    size_t strSize = std::strlen(obj.str);

    for (size_t i {0}; i != strSize; ++i) {
        obj.str[i] = std::toupper(obj.str[i]);
    }

    return obj;
}

MyString operator++(MyString &obj, int unsed) {
    MyString temp {obj};

    ++obj;

    return temp;
}

MyString operator+(const MyString &lhs, const MyString &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];

    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);

    MyString temp {buff};
    delete [] buff;

    return temp;
}

MyString &operator+=(MyString &lhs, const MyString &rhs) {
    lhs = lhs + rhs;

    return lhs;
}

MyString operator*(const MyString &lhs, size_t times) {
    MyString temp;

    for (size_t i {0}; i != times; ++i) {
        temp = temp + lhs;
    }

    return temp;
}

MyString &operator*=(MyString &lhs, size_t times) {
    lhs = lhs * times;

    return lhs;
}


bool operator==(const MyString &lhs, const MyString &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const MyString &lhs, const MyString &rhs) {
    return !(lhs == rhs);
}

bool operator<(const MyString &lhs, const MyString &rhs) {
    return (std::strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const MyString &lhs, const MyString &rhs) {
    return (std::strcmp(lhs.str, rhs.str) > 0);
}


std::ostream &operator<<(std::ostream &os, const MyString &obj) {
    os << obj.str;

    return os;
}

std::istream &operator>>(std::istream &is, MyString &obj) {
    char *buff = new char[1000];

    is >> buff;
    obj = MyString {buff};

    delete [] buff;

    return is;
}


void MyString::display() const {
    std::cout << str << std::endl;
}