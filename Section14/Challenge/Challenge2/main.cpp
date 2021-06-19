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
    obj1 = MyString {"Hi, hello"};
    obj1.display();

    return 0;
}