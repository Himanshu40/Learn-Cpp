#include <iostream>
#include <vector>
#include "Base.h"

using namespace std;

void displayObjCount() {
    cout << "Total object created = " << Base::getObjCount() << endl;
}

int main() {
    // To check if No-args constructor is working
    Base b1;
    b1.display();

    // To check if parameterized constructor is working
    Base b2 {5, 10};
    b2.display();

    // To check if deep copy constructor is working
    Base b3 {b2};
    b3.display();

    // To check if move constructor is working
    vector<Base> vec;

    vec.push_back(Base {6, 11});
    vec.push_back(Base {7, 12});

    // To check const with methods
    const Base b4;
    b4.display();

    // To check if static variable in class can print totalt number of objects created
    displayObjCount();

    // To check if deep copy assignment operator is working
    Base b5 {10, 20};
    b5.display();

    b5 = b1;
    b5.display();

    // To check if move assignment operator is working
    Base b6;
    b6.display();

    b6 = Base {11, 21};
    b6.display();

    b6 = {7, 8};
    b6.display();

    // To check if insertion operator overloading is working
    Base b7 {12, 13};
    cout << b7 << endl;

    // To check if both insertion and extraction operator overloading is working
    Base b8;
    cin >> b8;
    cout << b8 << endl;

    return 0;
}
