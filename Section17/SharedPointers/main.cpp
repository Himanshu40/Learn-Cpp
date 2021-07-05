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

void func(std::shared_ptr<Test> obj) {
    std::cout << "Use count for obj: " << obj.use_count() << std::endl;
}

int main() {
    std::shared_ptr<int> p1 {new int {100}};
    std::cout << "Use count for p1: " << p1.use_count() << std::endl;

    std::shared_ptr<int> p2 {p1};
    std::cout << "Use count for p1: " << p1.use_count() << std::endl;
    std::cout << "Use count for p2: " << p2.use_count() << std::endl;

    p1.reset();
    std::cout << "Use count for p1: " << p1.use_count() << std::endl;
    std::cout << "Use count for p2: " << p2.use_count() << std::endl;

    std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
    std::cout << "Use count for ptr: " << ptr.use_count() << std::endl;
    
    func(ptr);

    std::cout << "Use count for ptr: " << ptr.use_count() << std::endl;

    {
        std::shared_ptr<Test> ptr1 = ptr;
        std::cout << "Use count for ptr1: " << ptr1.use_count() << std::endl;
        std::cout << "Use count for ptr: " << ptr.use_count() << std::endl;
        
        {
            std::shared_ptr<Test> ptr2 = ptr;
            std::cout << "Use count for ptr2: " << ptr2.use_count() << std::endl;
            std::cout << "Use count for ptr: " << ptr.use_count() << std::endl;
            ptr.reset();
            std::cout << "Use count for ptr2: " << ptr2.use_count() << std::endl;
            std::cout << "Use count for ptr1: " << ptr1.use_count() << std::endl;
        }

        std::cout << "Use count for ptr1: " << ptr1.use_count() << std::endl;
        std::cout << "Use count for ptr: " << ptr.use_count() << std::endl;
        std::cout << "Use count for ptr1: " << ptr1.use_count() << std::endl;
    }

    std::cout << "Use count for ptr: " << ptr.use_count() << std::endl;


    return 0;
}
