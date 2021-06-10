#include <iostream>

int main() {
    int x{10};
    int &y = x;

    int &&z = 100;
    z = 200;

    return 0;
}