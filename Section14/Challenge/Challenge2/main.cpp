#include "MyString.h"

using namespace std;

int main() {
    MyString obj1 {"Hello"};
    obj1.display();
    
    MyString obj2 {obj1};
    obj2.display();


    return 0;
}