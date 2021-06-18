#include "MyString.h"

using namespace std;

int main() {
    MyString obj1 {"Hello"};
    // Deep copy constructor called
    MyString obj2 = obj1;

    obj1.display();
    obj2.display();

    // Move assignment operator called
    obj1 = "hello world";
    obj1.display();

    return 0;
}