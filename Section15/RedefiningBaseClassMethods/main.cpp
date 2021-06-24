#include <iostream>
#include "SavingsAccount.h"

using namespace std;

int main() {
    cout << "\n=====Account Class=====" << endl;

    Account a1 {1000.0};
    cout << a1 << endl;

    a1.deposit(500.0);
    cout << a1 << endl;

    a1.withdraw(1000);
    cout << a1 << endl;

    a1.withdraw(5000);      // Insufficient funds
    cout << a1 << endl;     // Account balance: 500

    cout << "\n=====Savings Account Class=====" << endl;

    SavingsAccount s1 {1000, 5.0};
    cout << s1 << endl;

    s1.deposit(1000);
    cout << s1 << endl;

    s1.withdraw(2000);
    cout << s1 << endl;

    s1.withdraw(1000);      // Insufficient funds
    cout << s1 << endl;     // Savings Account Balance: 50, Interest Rate: 5

    return 0;
}