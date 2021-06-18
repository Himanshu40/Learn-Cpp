#include "MyString.h"

using namespace std;

int main() {
    MyString obj1 {"Hello"};
    MyString obj2 {obj1};


    obj1.display();
    obj2.display();


    return 0;
}