#include <iostream>
#include <memory>
#include <vector>

class Test {
    private:
        int data;
    public:
        Test() : data {0} {
            std::cout << "\tTest Constructor {" << data << "}" << std::endl;
        }

        Test(int data) : data {data} {
            std::cout << "\tTest Constructor {" << data << "}" << std::endl;
        }

        int getData() const {
            return data;
        }

        ~Test() {
            std::cout << "\tTest Destructor {" << data << "}" << std::endl;
        }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    int value;

    for (int i {0}; i != num; ++i) {
        std::cout << "Enter data point [" << i << "] = ";
        std::cin >> value;

        // this way
        // std::shared_ptr<Test> ptr = std::make_shared<Test>(value);
        // vec.push_back(ptr);
        
        vec.push_back(std::make_shared<Test>(value));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "Displaying vector data" << std::endl;
    std::cout << "======================" << std::endl;

    for (const auto &i : vec) {
        std::cout << i->getData() << std::endl;
    }

    std::cout << "======================" << std::endl;
}

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vecPtr;
    vecPtr =  make();

    std::cout << "How many data points do you want to enter: ";
    
    int num;
    std::cin >> num;

    fill(*vecPtr, num);
    display(*vecPtr);

    return 0;
}
