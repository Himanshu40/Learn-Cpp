// Function Templates
#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

struct Person {
    std::string name;
    int age;

    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << rhs.name;

    return os;
}

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x {100};
    int y {200};
    
    func(x, y);
    swap(x, y);
    func(x, y);


    Person p1 {"Curly", 50};
    Person p2 {"Moe", 30};

    Person p3 = min(p1, p2);                                // Can't compare non-primitive types
                                                            // but after overloading <, it can
    std::cout << p3.name << " is younger" << std::endl;

    func(p1, p2);

    std::cout << min<int>(2, 3) << std::endl;               // 2
    std::cout << min(2, 3) << std::endl;                    // 2 and compiler can automatically deduce the types
    std::cout << min('A', 'B') << std::endl;                // A
    std::cout << min(12.5, 9.2) << std::endl;               // 9.2
    std::cout << min(5 + 2 * 2, 7 + 40) << std::endl;       // 9

    func<int, int>(10, 20);
    func(10, 20);
    func<char, double>('A', 12.4);
    func('A', 12.4);
    func(1000, "Testing");
    func(2000, std::string {"Frank"});

    return 0;
}
