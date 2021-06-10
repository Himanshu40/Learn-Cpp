#include <iostream>

int main() {
    int x{5};
    int y{6};

    std::cout << (x <=> y) << "\n";

    return 0;
}