// Function Objects
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct SquareFunctor {
    void operator()(int x) {
        std::cout << x * x << " ";
    }
};

template <typename T>
struct Displayer {
    void operator()(const T &data) {
        std::cout << data << " ";
    }
};

class Multiplier {
    private:
        int num {};
    public:
        Multiplier(int n) : num {n} {}
        
        int operator()(int n) const {
            return n * num;
        }
};

int main() {
    std::cout << "===TEST1===" << std::endl;

    SquareFunctor square;
    square(4);                      // square.operator()(4) displays 16

    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100);
    d2("Frank");

    std::cout << std::endl;

    std::cout << "===TEST2===" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};

    std::for_each(vec1.begin(), vec1.end(), square);
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), d2);
    std::cout << std::endl;

    std::cout << "===TEST3===" << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * x << " ";});
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * 10 << " ";});
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << " ";});
    std::cout << std::endl;
    
    std::for_each(vec2.begin(), vec2.end(), [](std::string x) {std::cout << x << " ";});
    std::cout << std::endl;

    std::cout << "===TEST4===" << std::endl;

    Multiplier mult {100};
    vec1 = {1, 2, 3, 4};

    // tranform changes the vector
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    vec1 = {1, 2, 3, 4};

    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) {return x * 100;});
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << " ";});
    std::cout << std::endl;

    return 0;
}
