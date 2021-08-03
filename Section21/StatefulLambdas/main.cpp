#include <iostream>
#include <vector>
#include <algorithm>

int globalX {1000};

// Used for test8()
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
    private:
        std::string name;
        int age;
    public:
        Person() = default;
        Person(std::string name, int age) : name {name}, age {age} {}
        Person(const Person &p) = default;
        ~Person() = default;

        std::string getName() const {
            return name;
        }
        
        void setName(std::string name) {
            this->name = name;
        }
        
        int getAge() const {
            return age;
        }
        
        void setAge(int age) {
            this->age = age;
        }

        auto changePerson1() {
            // Use this version for user-defined class
            return [this](std::string newName, int newAge) {
                name = newName;
                age = newAge;
            };
        }

        auto changePerson2() {
            // captured bu reference =. Deprecated in C++20
            return [=](std::string newName, int newAge) {
                name = newName;
                age = newAge;
            };
        }

        auto changePerson3() {
            return [&](std::string newName, int newAge) {
                name = newName;
                age = newAge;
            };
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << "[Person: " << p.name << ":" << p.age << "]";

    return os;
}

// Used for test9()
// Sometimes it can be struct instead of class
class Lambda {
    private:
        int y;
    public:
        Lambda(int y) : y {y} {}
        void operator()(int x) const {
            std::cout << x + y << std::endl;
        }
};

// Class used in the test10() example
class People {
    private:
        std::vector<Person> people;
        int maxPeople;
    public:
        People(int max = 10) : maxPeople(max) {}
        People(const People &p) = default;
        
        void add(std::string name, int age) {
            people.emplace_back(name, age);
        }

        void setMaxPeople(int max) {
            maxPeople = max;
        }

        int getMaxPeople() const {
            return maxPeople;
        }

        // This method returns a vector of Person objects in
        // people whose age
};

// Capture by value
// The global variable globalX cannot be captured because it is not
// within the reaching scope of the lambda. It an however still be accessed
// from within the lambda using normal name lookup rules
void test1() {
    std::cout << "===TEST1===" << std::endl;

    int localX {100};

    auto l = [localX]() {
        std::cout << localX << std::endl;
        std::cout << globalX << std::endl;
    };

    l();
}

// Capture by value - mutable
// The captured vairble x can only be modified within the lambda by
// using the mutable keyword. Note that this modifibality only pertains to
// the captured varible within the lambda body and not the actual varibale
void test2() {
    std::cout << "===TEST2===" << std::endl;

    int x {100};

    auto l = [x]() mutable {
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl;

    l();
    std::cout << x << std::endl;
}

// Capture by reference
// Any changes made to the captured reference variable within the lambda body
// will change the actual varibale.
void test3() {
    std::cout << "===TEST3===" << std::endl;

    int x {100};

    auto l = [&x]() mutable {
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl;    
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value
// The variable z is not captured by the lambda
void test4() {
    std::cout << "===TEST4===" << std::endl;

    int x {100};
    int y {200};
    int z {300};                        // Note that z is not captured in the lambda since it is not used.

    auto l = [=]() mutable {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

// Default capture by reference
// This time because all three varibales - x, y, z are used within
// the lambda body, all three of them will be captured by reference.
void test5() {
    std::cout << "===TEST5===" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [&]() {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Deault capture by value, capture y by reference
void test6() {
    std::cout << "===TEST6===" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [=, &y]() mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by reference, capture x and z by value
// Equibalent to test6()
void test7() {
    std::cout << "===TEST7===" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [&, x, z]() mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}


void test8() {
    std::cout << "===TEST8===" << std::endl;

    Person person ("Larry", 18);
    std::cout << person << std::endl;

    // Default capture [this]
    // This is the preferred way
    auto changePerson1 = person.changePerson1();
    changePerson1("Moe", 30);
    std::cout << person << std::endl;

    // Deafult capture [=]
    // This has been deprecated in C++20
    auto changePerson2 = person.changePerson2();
    changePerson2("Curly", 25);
    std::cout << person << std::endl;

    // Default capture [&]
    auto changePerson3 = person.changePerson3();
    changePerson3("Frank", 34);
    std::cout << person << std::endl;
}

// Lambda class equivalence example
void test9() {
    std::cout << "===TEST9===" << std::endl;

    int y {100};

    Lambda lambda1 {y};
    auto lambda2 = [y](int x) {std::cout << x + y << std::endl;};

    lambda1(200);
    lambda2(200);
}


void test10() {

}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    test10();

    return 0;
}
