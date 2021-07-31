// Stateless lambda expressions
// [] - empty capture lists
#include <iostream>
#include <string>
#include <vector>
#include <functional>           // for std::function
#include <algorithm>

class Person {
        friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
    private:
        std::string name;
        int age;
    public:
        Person(std::string name, int age) : name {name}, age {age} {}
        Person(const Person &p) : name (p.name), age {p.age} {}
        ~Person() = default;

        std::string getName() const {return name;}
        void setName(std::string name) {this->name = name;}
        int getAge() const {return age;}
        void setAge(int age) {this->age = age;}
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << "[ Person: " << p.name << ":" << p.age << " ]";

    return os;
}

void test1() {
    std::cout << "===TEST1===" << std::endl;

    []() {std::cout << "Hi" << std::endl;}();
    [](int x) {std::cout << x << std::endl;}(100);
    [](int x, int y) {std::cout << x + y << std::endl;}(100, 200);
}

// Using values and references as lambda params
void test2() {
    std::cout << "===TEST2===" << std::endl;

    auto l1 = []() {std::cout << "Hi" << std::endl;};
    l1();

    int num1 {100};
    int num2 {100};

    auto l2 = [](int x, int y) {std::cout << x + y << std::endl;};
    l2(10, 20);
    l2(num1, num2);

    auto l3 = [](int &x, int y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
        x = 1000;
        y = 2000;
    };

    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}

void test3() {
    std::cout << "===TEST3===" << std::endl;

}

int main() {
    // test1();
    // test2();
    test3();

    return 0;
}
