#include "MyString.h"

using namespace std;

int main() {
    MyString obj1 {"Hello"};
    // Deep copy constructor called
    MyString obj2 = obj1;

    // obj1.display();
    cout << obj1 << endl;
    // obj2.display();
    cout << obj2 << endl;

    // Move assignment operator called
    obj1 = "HELLO WORLD";
    // obj1.display();
    cout << obj1 << endl;

    obj1 = -obj1;
    // obj1.display();
    cout << obj1 << endl;

    obj1 = obj1 + ", HERO";
    // obj1.display();
    cout << obj1 << endl;

    obj1 += " TADA";
    // obj1.display();
    cout << obj1 << endl;

    obj1++;
    // obj1.display();
    cout << obj1 << endl;

    MyString obj3 {"hi"};
    obj3++;
    // obj3.display();
    cout << obj3 << endl;

    obj3 = obj3 * 4;
    // obj3.display();
    cout << obj3 << endl;

    cout << boolalpha;
    cout << (obj3 == obj1) << endl;
    cout << (obj3 != obj1) << endl;
    cout << (obj2 == obj1) << endl;
    cout << (obj3 > obj1) << endl;
    cout << (obj3 < obj1) << endl;

    MyString obj4;
    cin >> obj4;
    cout << obj4 << endl;

    return 0;
}
