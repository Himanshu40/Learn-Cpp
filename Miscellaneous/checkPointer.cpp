#include <iostream>

using namespace std;

int main() {
    int x[] {1, 2, 3, 4, 5};
    int *z {x};

    cout << *z << *(z + 1);

    return 0;
}