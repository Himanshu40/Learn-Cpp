#include <iostream>
#include <vector>
#include "Base.h"
#include "Derived.h"

using namespace std;

int main() {
    Derived obj1;
    obj1.display();

    // Derived obj2 {7, 8};
    // obj2.display();

    cout << "=====================" << endl;

    // Derived obj3 = obj2;
    // obj3.display();

    // vector<Derived> vec;
    // vec.push_back(Derived {1, 2});
    // vec.push_back(Derived {3, 4});
    // vec.push_back(Derived {5, 6});

    Derived obj4 {10, 11};
    obj4.display();

    cout << "=====================" << endl;

    // obj1 = obj4;
    // obj1.display();

    obj4 = {1, 2};
    obj4.display();

    return 0;
}
