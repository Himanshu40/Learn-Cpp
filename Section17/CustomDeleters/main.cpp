#include <iostream>
#include <memory>

class Test {
    private:
        int data;
    public:
        Test() : data {0} {
            std::cout << "Test Constructor {" << data << "}" << std::endl;
        }

        Test(int data) : data {data} {
            std::cout << "Test Constructor {" << data << "}" << std::endl;
        }

        int getData() const {
            return data;
        }

        ~Test() {
            std::cout << "Test Destructor {" << data << "}" << std::endl;
        }
};

void deleter(Test *ptr) {
    std::cout << "Using my custom function deleter" << std::endl;

    delete ptr;
}

int main() {
    {
        std::shared_ptr<Test> ptr1 {new Test {100}, deleter};
    }

    std::cout << "=================================" << std::endl;

    {
        std::shared_ptr<Test> ptr2 (new Test {1000},
            [] (Test *ptr) {
                std::cout << "Using custom lambda deleter" << std::endl;
                delete ptr;
            });
    }

    return 0;
}
