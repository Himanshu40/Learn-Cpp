// Iterators
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// display any vector of integers using range-based for loop
void display(const std::vector<int> &vec) {
    std::cout << "[";
    for (auto const &i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n===============" << std::endl;

    std::vector<int> nums1 {1, 2, 3, 4, 5};
    auto it = nums1.begin();

    std::cout << *it << std::endl;

    it++;
    std::cout << *it << std::endl;
    
    it += 2;
    std::cout << *it << std::endl;
    
    it -= 2;
    std::cout << *it << std::endl;

    it = nums1.end() - 1;
    std::cout << *it << std::endl;
}

void test2() {
    std::cout << "\n===============" << std::endl;

    // display all vector elements using an interator
    std::vector<int> nums1 {1, 2, 3, 4, 5};

    std::vector<int>::iterator it = nums1.begin();
    while (it != nums1.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    // change all vector elements to 0
    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;
        it++;
    }

    display(nums1);
}

void test3() {
    std::cout << "\n===============" << std::endl;
    
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    std::vector<int>::const_iterator it1 = nums1.begin();
    // auto it1 = nums1.cbegin();

    while (it1 != nums1.end()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    it1 = nums1.begin();
    while (it1 != nums1.end()) {
        //*it = 0;                        // Compiler error - read only
        it1++;
    }
}

void test4() {
    std::cout << "\n===============" << std::endl;

    // using a reverse iterator
    std::vector<int> vec {1, 2, 3, 4};
    // reverse iterator over vector of ints starts at 4
    auto it1 = vec.rbegin();

    while (it1 != vec.rend()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    std::cout << "\n===============" << std::endl;
    
    // const reverse iterator over a list
    std::list<std::string> name {"Larry", "Moe", "Curly"};
    // iterator over list of strings point to Curly
    auto it2 = name.crbegin();

    std::cout << *it2 << std::endl;
    it2++;
    std::cout << *it2 << std::endl;

    std::cout << "\n===============" << std::endl;

    // iterator over a map
    std::map<std::string, std::string> favorites {

    }
}

int main() {
    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}
