#include <iostream>
#include <memory>
#include "Account.h"
#include "AccountUtil.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"
#include "IllegalBalanceException.h"

using namespace std;

int main() {
    try {
        unique_ptr<Account> moesAccount = make_unique<CheckingAccount>("Moe", -10.0);
        cout << *moesAccount << endl;
    }
    catch (const IllegalBalanceException &ex) {
        cerr << "Couldn't create account - negative balance" << endl;
    }

    cout << "Program completed successfully" << endl;
    return 0;
}
