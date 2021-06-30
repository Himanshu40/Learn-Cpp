#include <iostream>

class Base final {
        int num;
    public:
        Base() : num {5} {}
        void display() {std::cout << num << std::endl;}
};

class Derived {
        int num1;
    public:
        Derived() : num1 {7} {}
        virtual void display() final {std::cout << num1 << std::endl;}
        virtual ~Derived();
};

class Derived1 : public Derived {
        int num2;
    public:
        Derived1() : num2 {8} {}
        virtual void display() {std::cout << num2 << std::endl;}     // Compiler Error : Can't Override
};

int main() {
    Derived *ptr = new Derived1();
    ptr->display();

    return 0;
}
