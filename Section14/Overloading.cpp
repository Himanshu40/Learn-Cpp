#include <iostream>
#include <cstring>

using namespace std;

class MyString {
        // C- Style string
        char *str;
    public:
        MyString();
        MyString(const char *s);
        MyString(const MyString &src);
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
    MyString empty;
    MyString larry{"Larry"};
    MyString stooge{larry};

    empty.display();
    larry.display();
    stooge.display();

    return 0;
}