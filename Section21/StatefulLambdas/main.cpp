#include <iostream>
#include <vector>
#include <algorithm>

int globalX {1000};

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
void test5() {

}

int main() {
    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}
