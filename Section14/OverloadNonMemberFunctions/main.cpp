#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    MyString larry {"Larry"};
    larry.display();

    larry =  -larry;
    larry.display();

    cout << boolalpha << endl;
    MyString moe {"Moe"};
    MyString stooge = larry;

    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;

    MyString stooges = "Larry" + moe;
    stooges.display();

    MyString twoStooges = moe + " " + "Larry";
    twoStooges.display();

    MyString threeStooges = moe + " " + larry + " " + "Curly";
    threeStooges.display();

    return 0;
}