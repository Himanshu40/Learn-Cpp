#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

int main() {
    cout << "\n========ACCOUNT========" << endl;

    Account acc {};
    acc.deposit(2000.0);
    acc.withdraw(500.0);

    cout << endl;

    Account *pAcc = new Account;
    pAcc->deposit(1000.0);
    pAcc->withdraw(500.0);
    delete pAcc;

    cout << "\n========SAVINGS ACCOUNT========" << endl;

    SavingsAccount acc1 {};
    acc1.deposit(2000.0);
    acc1.withdraw(500);

    cout << endl;

    SavingsAccount *pAcc1 = new SavingsAccount;
    pAcc1->deposit(1000.0);
    pAcc1->withdraw(500.0);
    delete pAcc1;

    cout << "\n================================" << endl;

    return 0;
}
