// The problem : This program only does static binding
#include <iostream>
#include <memory>

class Base {
    public:
        void sayHello() const {
            std::cout << "Hello - I'm a Base class object" << std::endl;
        }
};

class Derived : public Base {
    public:
        void sayHello() const {
            std::cout << "Hello - I'm a Derived class object" << std::endl;
        }
};

void greetings(const Base &obj) {
    std::cout << "Greetings: ";
    obj.sayHello();
}

int main() {
    Base b;
    b.sayHello();

    Derived d;
    d.sayHello();

    greetings(b);
    greetings(d);

    Base *ptr = new Derived();
    ptr->sayHello();            // Base::sayhello()

    // Smart Pointer
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->sayHello();           // Base::sayhello()

    delete ptr;

    return 0;
}
