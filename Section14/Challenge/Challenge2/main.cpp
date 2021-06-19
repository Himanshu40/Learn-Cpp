#include "MyString.h"

using namespace std;

int main() {
    MyString obj1 {"Hello"};
    obj1.display();
    
    // Deep copy constructor called
    MyString obj2 {obj1};
    obj2.display();

    MyString obj3 {"world"};
    // Copy assignment called
    obj1 = obj3;
    obj1.display();

    // Move assignment called
    obj1 = "hello world, HERO";
    obj1.display();

    // Move assignment called
    obj1 = MyString {"Hi, Hello"};
    obj1.display();

    cout << boolalpha;
    cout << (obj1 == obj2) << endl;
    cout << (obj1 != obj2) << endl;
    cout << (obj1 < obj2) << endl;
    cout << (obj1 > obj2) << endl;

    obj1 = -obj1;
    obj1.display();

    ++obj1;
    obj1.display();

    obj2++;
    obj2.display();

    obj3 = obj1 + obj2;
    obj3.display();

    obj3 += obj2;
    obj3.display();

    obj3 = obj1 * 4;
    obj3.display();

    obj3 *= 2;
    obj3.display();

    cout << obj1 << endl;
    cout << obj2 << endl;
    cout << obj3 << endl;

    return 0;
}