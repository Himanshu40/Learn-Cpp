#include <iostream>

using namespace std;

class Base {
    private:
        int value;
    public:
        Base() : Base {0} {
            cout << "Base No-args constructor" << endl;
        }

        Base(int x) : value {x} {
            cout << "Base int constructor" << endl;
        }

        Base(const Base &other) : Base {other.value} {
            cout << "Base copy constructor" << endl;
        }

        Base &operator=(const Base &rhs) {
            cout << "Base operator=" << endl;

            if (this != &rhs) {
                value = rhs.value;
            }

            return *this;
        }

        ~Base() {
            cout << "Base destructor" << endl;
        }
};

class Derived : public Base {
    private:
        int doubleValue;
    public:
        Derived() : Base(), doubleValue {0} {
            cout << "Derived No-args constructor" << endl;
        }

        Derived(int x) : Base(x), doubleValue {x * 2} {
            cout << "Derived int constructor" << endl;
        }

        Derived(const Derived &other) : Base(other), doubleValue {other.doubleValue} {
            cout << "Derived copy constructor" << endl;
        }

        Derived &operator=(const Derived &rhs) {
            cout << "Derived operator=" << endl;

            if (this != &rhs) {
                Base::operator=(rhs);
                doubleValue = rhs.doubleValue;
            }

            return *this;
        }

        ~Derived() {
            cout << "Derived destructor" << endl;
        }
};

int main() {
    Base b {100}; // Overloaded constructor
    Base b1 {b};  // Copy constructor
    b = b1;       // Copy assignment

    Derived d {100}; // Overloaded constructor
    Derived d1 {d};  // Copy constructor
    d = d1;          // Copy assignment

    Derived d2; // No-args constructor

    return 0;
}