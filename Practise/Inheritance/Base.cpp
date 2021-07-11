#include <iostream>
#include "Base.h"

Base::Base() : Base {0, 0} {
    std::cout << "Base No-args constructor for " << *size << std::endl;
}

Base::Base(int num, int sizeValue) : num {num} {
    size = new int;
    *size = sizeValue;

    std::cout << "Base Parameterized constructor for " << *size << std::endl;
}

Base::Base(const Base &src) : Base {src.num, *src.size} {
    std::cout << "Base Deep copy constructor for " << *size << std::endl;
}

Base::Base(Base &&src) noexcept : num {src.num}, size {src.size} {
    src.size = nullptr;

    std::cout << "Base Move constructor for " << *size << std::endl;
}

Base::~Base() {
    if (size != nullptr) {
        std::cout << "Base Destructor for " << *size << std::endl;
    }
    else {
        std::cout << "Base Destructor for nullptr" << std::endl;
    }

    delete size;
}


Base &Base::operator=(const Base &rhs) {
    std::cout << "Base Deep Copy assignment operator overloading for " << *rhs.size << std::endl;
    
    if (this != &rhs) {
        delete size;

        size = new int;
        *size = *rhs.size;
        num = rhs.num;
    }
        
    return *this;
}

Base &Base::operator=(Base &&rhs) noexcept {
    std::cout << "Base Move assignment operator overloading" << *rhs.size << std::endl;

    if (this != &rhs) {
        delete size;

        size = rhs.size;
        num = rhs.num;
        rhs.size = nullptr;
    }

    return *this;
}


void Base::display() const {
    std::cout << "Num = " << num << ", Size = " << *size << std::endl;
}
