#include <cstring>
#include "MyString.h"


// Overload insertion operator
std::ostream &operator<<(std::ostream &os, const MyString &rhs) {
    os << rhs.str;
    return os;
}

// Overload extraction operator
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
}

MyString::MyString(MyString &&src) noexcept : str {src.str} {
    src.str = nullptr;
}

MyString::~MyString() {
    delete [] str;
}


// Copy assignment
MyString &MyString::operator=(const MyString &rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = new char[std::strlen(rhs.str) + 1];
    strcpy(str, rhs.str);

    return *this;
}

// Move assignment
MyString &MyString::operator=(MyString &&rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete [] str;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}


// Returns the lowercase version of the object's string
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

// Pre-increment: convert the string uppercase
MyString &MyString::operator++() {
    size_t strSize = std::strlen(str) + 1;

    for (size_t i {0}; i != strSize; ++i) {
        str[i] = std::toupper(str[i]);
    }

    return *this;
}

// Post-increment: convert the string upper-case
MyString MyString::operator++(int unused) {
    MyString temp {*this};
    operator++();

    return temp;
}


// Concatenates two strings
MyString MyString::operator+(const MyString &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];

    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);

    MyString temp {buff};
    delete [] buff;

    return temp;
}

// Concatenate and assign
MyString &MyString::operator+=(const MyString &rhs) {
    *this = *this + rhs;
    return *this;
}

// Repeat
MyString MyString::operator*(size_t n) const {
    MyString temp;

    for (size_t i {0}; i != n; ++i) {
        temp = temp + *this;
    }

    return temp;
}

// Repeat and assign
MyString &MyString::operator*=(size_t n) {
    *this = *this * n;

    return *this;
}


// Returns true if the two strings are equal
bool MyString::operator==(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Returns true if the two strings are not equal
bool MyString::operator!=(const MyString &rhs) const {
    return !(rhs == *this);
}

// Returns true if the lhs string is lexically less than the rhs string
bool MyString::operator<(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

// Returns true if the lhs string is lexically greater than the rhs string
bool MyString::operator>(const MyString &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}
