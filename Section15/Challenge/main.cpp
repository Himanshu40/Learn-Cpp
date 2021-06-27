// Section 15 Challenge
#include <iostream>
#include <vector>
#include "SavingsAccount.h"
#include "AccountUtil.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Acoounts
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

    return 0;
}