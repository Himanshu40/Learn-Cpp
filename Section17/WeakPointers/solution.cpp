// Problem with shared ownership in Circular or Cyclic relationship
#include <iostream>
#include <memory>

class B;            // forward declaration

class A {
        std::shared_ptr<B> bPtr;
    public:
        void setB(std::shared_ptr<B> &b) {
            bPtr = b;
        }

        A() {std::cout << "A Constructor" << std::endl;}

        ~A() {std::cout << "A Destructor" << std::endl;}
};

class B {
        std::weak_ptr<A> aPtr;
    public:
        void setA(std::shared_ptr<A> &a) {
            aPtr = a;
        }

        B() {std::cout << "B constructor" << std::endl;}

        ~B() {std::cout << "B Destructor" << std::endl;}
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->setB(b);
    b->setA(a);
    
    return 0;
}
