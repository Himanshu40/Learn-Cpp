#include <iostream>
#include "Derived.h"

Derived::Derived() : Derived {0, 0} {
    std::cout << "Derived No-args constructor for " << *size1 << std::endl;
}

Derived::Derived(int num1, int sizeValue1) : Base(num1, sizeValue1), num1 {num1} {
    size1 = new int;
    *size1 = sizeValue1;

    std::cout << "Derived Parameterized constructor for " << *size1 << std::endl;
}

Derived::Derived(const Derived &src) : Base(src), num1 {src.num1} {
    size1 = new int;
    *size1 = *src.size1;

    std::cout << "Derived Deep copy constructor for " << *size1 << std::endl;
}

Derived::Derived(Derived &&src) noexcept : Base(std::move(src)), num1 {src.num1}, size1 {src.size1} {
    src.size1 = nullptr;

    std::cout << "Derived Move constructor for " << *size1 << std::endl;
}

Derived::~Derived() {
    if (size1 != nullptr) {
        std::cout << "Derived Destructor for " << *size1 << std::endl;
    }
    else {
        std::cout << "Derived Destructor for nullptr" << std::endl;
    } 

    delete size1;
}


Derived &Derived::operator=(const Derived &rhs) {
    std::cout << "Derived Deep Copy assignment operator overloading for " << *rhs.size1 << std::endl;

    if (this != &rhs) {
        Base::operator=(rhs);
        delete size1;
        
        size1 = new int;
        *size1 = *rhs.size1;
        num1 = rhs.num1;
    }

    return *this;
}

Derived &Derived::operator=(Derived &&rhs) noexcept {
    std::cout << "Derived Move assignment operator overloading for " << *rhs.size1 << std::endl;

    if (this != &rhs) {
        Base::operator=(std::move(rhs));
        delete size1;

        size1 = rhs.size1;
        num1 = rhs.num1;

        rhs.size1 = nullptr;
    }

    return *this;
}


void Derived::display() const {
    Base::display();

    std::cout << "Num1 = " << num1 << ", Size1 = " << *size1 << std::endl;
}
