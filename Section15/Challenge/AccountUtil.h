#ifndef _ACCOUNTUTIL_H_
#define _ACCOUNTUTIL_H_

#include <vector>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"

// Utility helper functions for Account Class
void display(const std::vector<Account> &acc);
void deposit(std::vector<Account> &acc, double amount);
void withdraw(std::vector<Account> &acc, double amount);

// Utility helper functions for Savings Account Class
void display(const std::vector<SavingsAccount> &acc);
void deposit(std::vector<SavingsAccount> &acc, double amount);
void withdraw(std::vector<SavingsAccount> &acc, double amount);

// Utility helper functions for Checking Account Class
void display(const std::vector<CheckingAccount> &acc);
void deposit(std::vector<CheckingAccount> &acc, double amount);
void withdraw(std::vector<CheckingAccount> &acc, double amount);

// Utility helper functions for Trust Account Class
void display(const std::vector<TrustAccount> &acc);
void deposit(std::vector<TrustAccount> &acc, double amount);
void withdraw(std::vector<TrustAccount> &acc, double amount);


#endif
