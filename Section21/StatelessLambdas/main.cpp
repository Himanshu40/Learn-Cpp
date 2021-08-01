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

// Using value and reference objects as lambda params
void test3() {
    std::cout << "===TEST3===" << std::endl;

    Person stooge {"Larry", 18};
    std::cout << stooge << std::endl;

    auto l4 = [](Person p) {
        std::cout << p << std::endl;
    };
    l4(stooge);

    auto l5 = [](const Person &p) {
        std::cout << p << std::endl;
    };
    l5(stooge);

    auto l6 = [](Person &p) {
        p.setName("Frank");
        p.setAge(25);
        std::cout << p << std::endl;
    };
    l6(stooge);

    std::cout << stooge << std::endl;
}

// using std::function as a parameter in C++14 and greater
// or
// auto as parameter type in C++20
void filterVector(const std::vector<int> &vec, std::function<bool(int)> func) {
// void filterVector(const std::vector<int> &vec, auto func) {
    std::cout << "[ ";

    for (int i : vec) {
        if (func(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << "]" << std::endl;
}

// Passing a lambda to a function
void test4() {
    std::cout << "===TEST4===" << std::endl;
    
    std::vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filterVector(nums, [](int x) {return x > 50;});
    filterVector(nums, [](int x) {return x <= 30;});
    filterVector(nums, [](int x) {return x >= 30 && x <= 60;});
}

// Used for test5
auto makeLambda() {
    return []() {std::cout << "This lambda was made using the maleLambda function!" << std::endl;};
}

// returning a lambda from a function
void test5() {
    std::cout << "===TEST5===" << std::endl;

    auto l5 = makeLambda();
    l5();
}

// Using auto in the lambda paramter list
void test6() {
    std::cout << "===TEST6===" << std::endl;

    auto l6 = [](auto x, auto y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
    };

    l6(10, 20);
    l6(10.3, 20);
    l6(10.5, 20.54);
    l6(Person("Larry", 18), Person("Curly", 22));
}

// Simple lamda examples with std::sort and std::for_each
void test7() {
    std::cout << "===TEST7===" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };

    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.getName() < p2.getName();
    });

    std::for_each(begin(stooges), end(stooges), [](const Person &p) {
        std::cout << p << std::endl;
    });

    std::cout << std::endl;

    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.getAge() < p2.getAge();
    });
}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    test7();

    return 0;
}
