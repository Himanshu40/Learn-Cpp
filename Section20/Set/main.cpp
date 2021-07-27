#include <iostream>
#include <set>

class Person {
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    public:
        Person() : name {"Unkown"}, age {0} {}

        Person(std::string name, int age) : name {name}, age {age} {}

        bool operator<(const Person &rhs) const {
            return this->age < rhs.age;
        }

        bool operator==(const Person &rhs) const {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;

    return os;
}

template <typename T>
void display(const std::set<T> &set) {
    std::cout << "[";

    for (const auto &elem : set) {
        std::cout << elem << " ";
    }

    std::cout << "]" << std::endl;
}

void test1() {
    // Sets
    std::cout << "===TEST1===" << std::endl;

    std::set<int> s1 {1, 4, 3, 5, 2};
    display(s1);

    s1 = {1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5};
    display(s1);

    s1.insert(0);
    s1.insert(10);

    display(s1);

    if (s1.count(10)) {
        std::cout << "10 is in the set" << std::endl;
    }
    else {
        std::cout << "10 is not in the set" << std::endl;
    }

    auto it = s1.find(5);
    if (it != s1.end()) {
        std::cout << "Found: " << *it << std::endl;
    }

    s1.clear();
    display(s1);
}

void test2() {
    std::cout << "===TEST2===" << std::endl;

    std::set<Person> stooges {
        {"larry", 1},
        {"moe", 2},
        {"curly", 3}
    };

    display(stooges);                           // Note the order of display! operator<

    stooges.emplace("James", 50);
    display(stooges);

    stooges.emplace("Frank", 50);               // NO -- 50 already exists
    display(stooges);

    auto it = stooges.find(Person {"moe", 2});
    if (it != stooges.end()) {
        stooges.erase(it);
    }

    display(stooges);

    it = stooges.find(Person {"XXX", 50});      // Will remove James and uses operator<

    if (it != stooges.end()) {
        stooges.erase(it);
    }

    display(stooges);
}

void test3() {
    std::cout << "===TEST3===" << std::endl;

    std::set<std::string> s {"A", "B", "C"};
    display(s);

    auto result = s.insert("D");                // result is std::pair. Returns an iterator or a copy and boolean value
    display(s);

    std::cout << std::boolalpha;
    std::cout << "First: " << *(result.first) << std::endl;
    std::cout << "Second: " << result.second << std::endl;

    std::cout << std::endl;

    result = s.insert("A");
    display(s);

    std::cout << "First: " << *(result.first) << std::endl;
    std::cout << "Second: " << result.second << std::endl;
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}
