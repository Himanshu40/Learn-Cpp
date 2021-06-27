// Section 15 Challenge
#include <iostream>
#include <vector>
#include "AccountUtil.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000});
    accounts.push_back(Account {"Curly", 5000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings Accounts

    vector<SavingsAccount> savAccounts;

    savAccounts.push_back(SavingsAccount {});
    savAccounts.push_back(SavingsAccount {"Superman"});
    savAccounts.push_back(SavingsAccount {"Batman", 2000});
    savAccounts.push_back(SavingsAccount {"WonderWoman", 5000, 5.0});

    display(savAccounts);
    deposit(savAccounts, 1000);
    withdraw(savAccounts, 2000);

    // Checking Accounts

    vector<CheckingAccount> checkAccounts;

    checkAccounts.push_back(CheckingAccount {});
    checkAccounts.push_back(CheckingAccount {"Himanshu"});
    checkAccounts.push_back(CheckingAccount {"Chandrakant", 2000});
    checkAccounts.push_back(CheckingAccount {"Sabyasachi", 5000});

    display(checkAccounts);
    deposit(checkAccounts, 1000);
    withdraw(checkAccounts, 2000);

    // Trust Accounts

    vector<TrustAccount> trustAccounts;

    trustAccounts.push_back(TrustAccount {});
    trustAccounts.push_back(TrustAccount {"Athos", 10000, 5.0});
    trustAccounts.push_back(TrustAccount {"Porthos", 20000, 4.0});
    trustAccounts.push_back(TrustAccount {"Aramis", 30000});

    display(trustAccounts);
    deposit(trustAccounts, 1000);
    withdraw(trustAccounts, 3000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawal is > 20% of the balance
    for (int i {1}; i <= 5; ++i) {
        withdraw(trustAccounts, 1000);
    }

    return 0;
}
