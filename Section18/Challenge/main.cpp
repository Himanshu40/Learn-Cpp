#include <iostream>
#include <memory>
#include "Account.h"
#include "AccountUtil.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std;

int main() {
    try {
        unique_ptr<Account> moesAccount = make_unique<CheckingAccount>("Moe", 1000.0);
        cout << *moesAccount << endl;

        moesAccount->withdraw(2000);
    }
    catch (const IllegalBalanceException &ex) {
        cerr << ex.what() << endl;
    }
    catch (const InsufficientFundsException &ex) {
        cerr << ex.what() << endl;
    }

    cout << "Program completed successfully" << endl;
    return 0;
}
