#ifndef _ACCOUNTUTIL_H_
#define _ACCOUNTUTIL_H_

#include <vector>
#include "Account.h"
#include "SavingsAccount.h"

// Utility helper functions for Account Class
void display(const std::vector<Account> &acc);
void deposit(std::vector<Account> &acc, double amount);
void withdraw(std::vector<Account> &acc, double amount);

// Utility helper functions for Savings Account Class
void display(const std::vector<SavingsAccount> &acc);
void deposit(std::vector<SavingsAccount> &acc, double amount);
void withdraw(std::vector<SavingsAccount> &acc, double amount);

#endif
