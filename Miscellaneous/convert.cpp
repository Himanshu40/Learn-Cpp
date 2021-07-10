#include <iostream>

using namespace std;

int main() {
    int x {100};
    int y {15};
    double z;

    z = x / y;

    cout << z << "\n"; // Yields arbitary integer :-)

    return 0;
}