#include "Base.h"


int Base::objCount {0};

Base::Base() : Base {0, 0} {
    std::cout << "No-args constructor called for " << *data << std::endl;
}

Base::Base(int size, int value) : size {size} {
    data =  new int;
    *data = value;
    ++objCount;

    std::cout << "Parameterized constructor called for " << *data << std::endl;
}

Base::Base(const Base &obj) : Base {obj.size, *obj.data} {
    std::cout << "Deep copy constructor called for " << *data << std::endl;
}

Base::Base(Base &&obj) noexcept : size {obj.size}, data {obj.data} {
    obj.data = nullptr;

    std::cout << "Move constructor called for " << *data << std::endl;
}

Base::~Base() {
    if (data != nullptr) {
        std::cout << "Destructor called for " << *data << std::endl;
        --objCount;
    }
    else {
        std::cout << "Destructor called for nullptr" << std::endl;
    }

    delete data;
}


Base &Base::operator=(const Base &rhs) {
    std::cout << "Deep copy assignment operator" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete data;
    data = new int;
    *data = *rhs.data;
    size = rhs.size;

    return *this;
}

Base &Base::operator=(Base &&rhs) {
    std::cout << "Move assignment operator" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    delete data;
    data = rhs.data;
    size = rhs.size;
    rhs.data = nullptr;

    return *this;
}


std::ostream &operator<<(std::ostream &os, const Base &rhs) {
    os << "Size = " << rhs.size << ", Data = " << *rhs.data;

    return os;
}

std::istream &operator>>(std::istream &is, Base &rhs) {
    int size {};

    std::cout << "Enter the size: " << std::endl;
    is >> size;

    std::cout << "Enter the data: " << std::endl;
    int *data = new int;
    is >> *data;

    rhs = Base {size, *data};
    delete data;

    return is;
}


void Base::display() const {
    std::cout << "Size = " << size << ", Data = " << *data << std::endl;
}

int Base::getObjCount() {
    return objCount;
}
