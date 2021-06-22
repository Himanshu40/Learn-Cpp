#include <iostream>

using namespace std;

class Base {
    private:
        int value;
    public:
        Base() : value {0} {
            cout << "Base no-args constructor" << endl;
        }

        Base(int x) : value {x} {
            cout << "Base (int) overload constructor" << endl;
        }

        ~Base() {
            cout << "Base Destructor" << endl;
        }
};

class Derived : public Base {
    // using Base::Base;
    public:
        int doubledValue;
    public:
        Derived() : Base(), doubledValue {0} {
            cout << "Derived no-args constructor" << endl;
        }

        Derived(int x) : Base(x), doubledValue {x * 2} {
            cout << "Derived (int) overload constructor" << endl;
        }

        ~Derived() {
            cout << "Derived Destructor" << endl;
        }
};

int main() {
    // Base b;
    // Base b1 {100};
    Derived d1;
    Derived d2 {100};

    return 0;
}