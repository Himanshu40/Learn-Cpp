#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class MyString {
        // C- Style string
        char *str;
    public:
        MyString();
        MyString(const char *s);
        MyString(const MyString &src);
        // Copy Assignment
        MyString &operator=(const MyString &rhs);
        ~MyString();
        void display() const;
        int getLength() const;
        const char *getStr() const; 
};

// No-args delegate Constructor 
MyString::MyString() : MyString{nullptr} {}

// Overloaded Constructor
MyString::MyString(const char *s) : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Deep Copy constructor
MyString::MyString(const MyString &src) : MyString{src.str} {}

// Copy Assignment
MyString &MyString::operator=(const MyString &rhs) {
    cout << "Copy Assignment" << endl;

    if (this == &rhs) {
        return *this;
    }

    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);

    return *this;
}

// Destructor
MyString::~MyString() {
    delete [] str;
}

void MyString::display() const {
    cout << str << ":" << getLength() << endl;
}

int MyString::getLength() const {
    return strlen(str);
}

const char *MyString::getStr() const {
    return str;
}

int main() {
    MyString a{"Hello"};
    MyString b;
    b = a;

    b = "This is a test";

    MyString empty;
    MyString larry{"Larry"};
    MyString stooge{larry};
    MyString stooges;

    empty.display();
    
    empty = stooge;

    larry.display();
    stooge.display();
    empty.display();

    stooge = "Larry, Moe, and Curly";
    stooges.display();

    vector<MyString> stoogesVec;
    stoogesVec.push_back("Larry");
    stoogesVec.push_back("Moe");
    stoogesVec.push_back("Curly");

    cout << "=== Loop 1 ===" << endl;
    for (const MyString &s:stoogesVec) {
        s.display();
    }

    cout << "=== Loop 2 ===" << endl;
    for (MyString &s:stoogesVec) {
        // Copy-Assignment
        s = "Changed";
    }
    
    cout << "=== Loop 3 ===" << endl;
    for (const MyString &s:stoogesVec) {
        s.display();
    }

    return 0;
}