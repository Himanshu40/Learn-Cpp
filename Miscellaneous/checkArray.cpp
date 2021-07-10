#include <iostream>

using namespace std;

int main() {

    int x[] {1, 3, 4, 5, 6, 7};
    int *y {nullptr};
    double *z {nullptr};
    int a;

    cout << sizeof x << endl;
    cout << sizeof y << " " << sizeof z;
    cout << sizeof a;

    return 0;
}