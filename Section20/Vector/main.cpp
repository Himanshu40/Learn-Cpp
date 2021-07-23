#include <iostream>
#include <vector>
#include <algorithm>

class Person {
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    public:
        Person() = default;

        Person(std::string name, int age)
            : name {name}, age {age} {}
        
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

// Use for_each and a lambda expression to display vector elements
void display2(const std::vector<int> &vec) {
    std::cout << "[";

    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " ";});

    std::cout << "]" << std::endl;
}

// template function to display any vector
template <typename T>
void display(const std::vector<T> &vec) {
    std::cout << "[";

    for (const auto &elem : vec) {
        std::cout << elem << " ";
    }

    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n===TEST1===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);

    vec = {2, 4, 5, 6};
    display2(vec);

    std::vector<int> vec1 (10, 100);                // ten 100s in the vec
    display(vec1);
}

void test2() {
    std::cout << "\n===TEST2===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);

    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "\nvec max size: " << vec.max_size() << std::endl;
    std::cout << "\nvec capacity: " << vec.capacity() << std::endl;

    vec.push_back(6);
    display(vec);

    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "\nvec max size: " << vec.max_size() << std::endl;
    std::cout << "\nvec capacity: " << vec.capacity() << std::endl;

    vec.shrink_to_fit();        // C++11
    display(vec);

    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "\nvec max size: " << vec.max_size() << std::endl;
    std::cout << "\nvec capacity: " << vec.capacity() << std::endl;

    vec.reserve(100);
    display(vec);

    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "\nvec max size: " << vec.max_size() << std::endl;
    std::cout << "\nvec capacity: " << vec.capacity() << std::endl;
}

void test3() {
    std::cout << "\n===TEST3===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);

    vec[0] = 100;
    vec.at(1) = 200;                        // Bound checking happens

    display(vec);
}

void test4() {
    std::cout << "\n===TEST4===" << std::endl;

    std::vector<Person> stooges;

    Person p1 {"Larry", 18};
    display(stooges);

    stooges.push_back(p1);
    display(stooges);

    stooges.push_back(Person {"Moe", 25});
    display(stooges);

    stooges.emplace_back("Curly", 30);
    display(stooges);
}

void test5() {
    std::cout << "\n===TEST5===" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };

    display(stooges);

    std::cout << "\nFront: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;

    stooges.pop_back();
    display(stooges);
}

void test6() {
    std::cout << "\n===TEST6===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);

    vec.clear();                                // Removes all the elements
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // erase all even numbers
    auto it = vec.begin();

    while (it != vec.end()) {
        if (*it % 2 == 0) {
            vec.erase(it);
        }
        else {
            it++;
        }
    }

    display(vec);
}

void test7() {
    std::cout << "\n===TEST7===" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20, 30, 40, 50};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

void test8() {
    std::cout << "\n===TEST8===" << std::endl;

    std::vector<int> vec1 {1, 21, 3, 40, 12};
    display(vec1);

    std::sort(vec1.begin(), vec1.end());

    display(vec1);
}

void test9() {
    std::cout << "\n===TEST9===" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    // std::back_inserter constructs a back-insert iterator that inserts new elements
    // at the end of the container it applied to.
    // There is also a front_inserter that can be used with deques and lists
    // COpy one list to another using an iterator and back_inserter
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    // copy_if the element is even
    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec2 = {10, 20};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
        [](int x) {return x % 2 == 0;});

    display(vec1);
    display(vec2);
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
    test9();

    return 0;
}
