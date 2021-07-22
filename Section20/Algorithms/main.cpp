// Algorithms
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person {
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

// Find an element in a container
void findTest() {
    std::cout << "\n==================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    // Find 3 in vec and here loc is an iterator
    auto loc = std::find(std::begin(vec), std::end(vec), 3);

    if (loc != std::end(vec)) {
        std::cout << "Found the number: " << *loc << std::endl;
    }
    else {
        std::cout << "Coudn't find the number" << std::endl;
    }

    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };

    auto loc1 = std::find(players.begin(), players.end(), Person {"Moe", 20});

    if (loc1 != players.end()) {
        std::cout << "Found Moe " << std::endl;
    }
    else {
        std::cout << "Moe not found" << std::endl;
    }
}

// Count the number
void countTest() {
    std::cout << "\n==================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1};

    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurrences found" << std::endl;          // 3 occurrences
}

// Count the number of occurrences of an element in a container
// based on a predicate using a lambda expression
void countIfTest() {
    std::cout << "\n==================" << std::endl;

    // count only if the element is even
    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1, 100};

    int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 != 0;});
    std::cout << num << " odd numbers found" << std::endl;

    // count elements in vec which are >= 5
    num = std::count_if(vec.begin(), vec.end(), [](int x) {return x >= 5;});
    std::cout << num << " numbers are >= 5" << std::endl;
}

// Replaces occurrences of elements in a container
void replaceTest() {
    std::cout << "\n==================" << std::endl;
    
    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1};
    for (auto i : vec) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i : vec) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void allOfTest() {
    std::cout << "\n==================" << std::endl;

    std::vector<int> vec {1, 3, 5, 7, 9, 1, 3, 13, 19, 5};

    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x > 10;})) {
        std::cout << "All the elements are > 10" << std::endl;
    }
    else {
        std::cout << "Not all the elements are > 10" << std::endl;
    }

    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x < 20;})) {
        std::cout << "All the elements are < 20" << std::endl;
    }
    else {
        std::cout << "Not all the elements are < 20" << std::endl;
    }
}

// Transform elements in a container - string in this example
void stringTransformTest() {
    std::cout << "\n==================" << std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;

    // ::toupper is global scope
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);

    std::cout << "After transform: " << str1 << std::endl;
}

int main() {
    findTest();
    countTest();
    countIfTest();
    replaceTest();
    allOfTest();
    stringTransformTest();

    return 0;
}
