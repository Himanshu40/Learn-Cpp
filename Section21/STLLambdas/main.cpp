#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>      // for std::iodata

// Used for test5
class Person {
        friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
    private:
        std::string name;
        int age;
    public:
        Person(std::string name, int age) : name {name}, age {age} {};
        Person(const Person &p) : name {p.name}, age {p.age} {}
        ~Person() = default;

        std::string getName() const {return name;}
        void setName(std::string name) {this->name = name;}
        int getAge() const {return age;}
        void setAge(int age) {this->age = age;}
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " << rhs.name << ":" << rhs.age << "]";

    return os;
}

// The following classes are used for test7
class PasswordValidator1 {
    private:
        char restrictedSymbol {'$'};
    public:
        bool isValid(std::string password) {
            return std::all_of(password.begin(), password.end(),
                [this](char character) {return character != restrictedSymbol;});
        }
};

class PasswordValidator2 {
    private:
        std::vector<char> restrictedSymbols {'!', '$', '+'};
    public:
        bool isValid(std::string password) {
            return std::all_of(password.begin(), password.end(),
                [this](char character) {return std::none_of(restrictedSymbols.begin(), restrictedSymbols.end(),
                    [character](char symbol) {return character == symbol;});});
        }
};

// for each - Non-modifying sequence operation
// for STL algorithms
void test1() {
    std::cout << "===TEST1===" << std::endl;

    std::vector<int> nums {10, 20, 30, 40, 50};
    std::for_each(nums.begin(), nums.end(),
        [](int num) {std::cout << num << " ";});
    
    std::cout << std::endl;
}

// is_permuatation - Non-modifying sequence operation
// Tests whether two triangles are equivalent
// Triangles are defined by a vector of three poitns in any order.
// Regardless of the order of points, if two triangles contan the
// same three points then they are equibalent.
// This is determined by testing whether one sequence of points is a
// permutation of another using a predicate lambda to compare points.
void test2() {
    std::cout << "===TEST2===" << std::endl;

    struct Point {
        int x;
        int y;
    };

    Point pt1 {1, 2};
    Point pt2 {4, 3};
    Point pt3 {3, 5};
    Point pt4 {3, 1};

    std::vector<Point> triangle1 {pt1, pt2, pt3};
    std::vector<Point> triangle2 {pt2, pt3, pt1};
    std::vector<Point> triangle3 {pt1, pt2, pt4};

    // Test whether triangle1 and triangle2 are equivalent
    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), 
        [](Point lhs, Point rhs) {return lhs.x == rhs.x && lhs.y == rhs.y;})) {
        std::cout << "Triangle 1 and Triangle 2 are equivalent" << std::endl;            
    }
    else {
        std::cout << "Triangle 1 and Triangle 2 are not equivalent" << std::endl;            
    }

    
    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), 
        [](Point lhs, Point rhs) {return lhs.x == rhs.x && lhs.y == rhs.y;})) {
        std::cout << "Triangle 1 and Triangle 3 are equivalent" << std::endl;            
    }
    else {
        std::cout << "Triangle 1 and Triangle 3 are not equivalent" << std::endl;            
    }    
}

// transform - Modifying sequence operation
// In this case, test score is increased by 5 points
void test3() {
    std::cout << "===TEST3===" << std::endl;

    std::vector<int> testScores {93, 88, 75, 68, 65};
    int bonusPoints {5};

    std::transform(testScores.begin(), testScores.end(), testScores.begin(),
        [bonusPoints](int score) {return score += bonusPoints;});

    for (auto score : testScores) {
        std::cout << score << " ";
    }

    std::cout << std::endl;
}

// remove_if - Modifying sequence operation
// The remove_if function removes all elements for which the predicate
// lambda returns true. The way in which it does this is by replacing
// the elements for which the predicate returns false.
// In this case, the erase-remove idiom is used to remove all even numbers from the nums.
void test4() {
    std::cout << "===TEST4===" << std::endl;

    std::vector<int> nums {1, 2, 3, 4, 5};

    nums.erase(std::remove_if(nums.begin(), nums.end(),
        [](int num) {return num % 2 == 0;}), nums.end());

    for (auto num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}


void test5() {
    std::cout << "===TEST5===" << std::endl;

    Person person1 ("Larry", 18);
    Person person2 ("Moe", 30);
    Person person3 ("Curly", 25);

    std::vector<Person> people {person1, person2, person3};

    // Sort people by name in ascending order
    std::sort(people.begin(), people.end(),
        [](Person lhs, Person rhs) {return lhs.getName() < rhs.getName();});

    // Displays people sorted by name in ascending order
    for (Person person : people) {
        std::cout << person << std::endl;
    }
    std::cout << std::endl;

    // Sort people by age in descending order
    std::sort(people.begin(), people.end(),
        [](Person lhs, Person rhs) {return lhs.getAge() > rhs.getAge();});

    // Displays people sorted by age in descending order
    for (Person person : people) {
        std::cout << person << std::endl;
    }
    std::cout << std::endl;
}

// all_of - Non-modifying sequence operation
// Tests whether all elements contained within the sequence satisfy the
// condition defined by the passed predicate lambda
bool inBetween(const std::vector<int> &nums, int startValue, int endValue) {
    bool result {false};

    result = std::all_of(nums.begin(), nums.end(),
        [startValue, endValue](int value) {return value >= startValue && value <= endValue;});

    return result;
}

void test6() {
    std::cout << "===TEST6===" << std::endl;
    std::cout << std::boolalpha;

    std::vector<int> nums(10);
    // Set these 10 integers all the way to 10 e.g 1, 2, 3, ... 10
    std::iota(nums.begin(), nums.end(), 1);

    for (auto num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    std::cout << inBetween(nums, 50, 60) << std::endl;
    std::cout << inBetween(nums, 1, 10) << std::endl;
    std::cout << inBetween(nums, 5, 7) << std::endl;
}

// all_of - Non-modifying sequnce operation
// Tests whether all elements contained within the sequence satisfy the
// condition defined by the passed predicate lambda.
void test7() {
    std::cout << "===TEST7===" << std::endl;

    // PaswordValidator1
    std::string password {"hollywood1$"};
    PasswordValidator1 pv1;

    // Test whether password is valid
    if (pv1.isValid(password)) {
        std::cout << "The password " << password << " is valid." << std::endl;
    }
    else {
        std::cout << "The password " << password << " is not valid." << std::endl;
    }

    password = "hollywood1";

    // Test whether new password is valid or not
    if (pv1.isValid(password)) {
        std::cout << "The password " << password << " is valid." << std::endl;
    }
    else {
        std::cout << "The password " << password << " is not valid." << std::endl;
    }

    // PasswordValidator2
    password = "C++Rocks!";
    PasswordValidator2 pv2;

    // Test whether new password is valid or not
    if (pv2.isValid(password)) {
        std::cout << "The password " << password << " is valid." << std::endl;
    }
    else {
        std::cout << "The password " << password << " is not valid." << std::endl;
    }

    password = "CPlusPlusRocks!";

    // Test whether new password is valid or not
    if (pv2.isValid(password)) {
        std::cout << "The password " << password << " is valid." << std::endl;
    }
    else {
        std::cout << "The password " << password << " is not valid." << std::endl;
    }

    password = "CPlusPlusRocks";

    // Test whether new password is valid or not
    if (pv2.isValid(password)) {
        std::cout << "The password " << password << " is valid." << std::endl;
    }
    else {
        std::cout << "The password " << password << " is not valid." << std::endl;
    }
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}
