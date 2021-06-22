#include <iostream>

using namespace std;

class Base {
    // Note Friends of Base have access to all
    private:
        int a;
    protected:
        int b;
    public:
        int c;

        // Member method has access to all
        void display() {
            cout << a << ", " << b << ", " << c << endl;
        }
};

class Derived : public Base {
    // Note Friends of Derived have access to only what Derived has access to

    // c will be public
    // b will be protected
    // a will not be accessible
    public:
        void accessBaseMembers() {
            c = 100; // OK
            b = 200; // OK
            //d = 300; // Not accessible
        }
};

int main() {
    cout << "=== Base member access from base objects ===" << endl;

    Base base;
    
    base.c = 100; // OK
    // base.b = 200; // Compiler error
    // base.d = 300; // Compiler error

    cout << "=== Base member access from derived objects ===" << endl;

    Derived d;

    d.c = 100; // OK
    // d.b = 200; // Compiler error
    // d.c= 300; // // Compiler error

    return 0;
}