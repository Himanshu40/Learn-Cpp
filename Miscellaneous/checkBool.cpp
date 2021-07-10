#include <iostream>

using namespace std;

int main() {

    bool x, y;
    x = (50 != 100);
    y = (150 != 100);

    cout << boolalpha; 
    cout << x << "\n";
    cout << y << "\n";
    cout << noboolalpha << x << "\n";
    cout << y << "\n";

    return 0;
}