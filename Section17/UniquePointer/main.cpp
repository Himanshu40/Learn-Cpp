#include <iostream>
#include <memory>

class Test {
        int data;
    public:
        Test() : data {0} {
            std::cout << "Constructor called for " << data << std::endl;
        }

        Test(int data) : data {data} {
            std::cout << "Constructor called for " << data << std::endl;
        }

        ~Test() {
            std::cout << "Destructor called for " << data << std::endl;
        }
};

int main() {
    std::unique_ptr<Test> t1 {new Test {100}};
    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);

    t2 = std::move(t1);

    if (!t1) {
        std::cout << "t1 is nullptr" << std::endl;
    }

    return 0;
}
