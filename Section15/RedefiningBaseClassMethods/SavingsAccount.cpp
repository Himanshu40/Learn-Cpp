#include "SavingsAccount.h"


SavingsAccount::SavingsAccount() : SavingsAccount {0.0, 0.0} {
}

SavingsAccount::SavingsAccount(double balance, double intRate) : Account(balance), intRate {intRate} {
}

void SavingsAccount::deposit(double amount) {
    amount = amount + (amount * intRate / 100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &acc) {
    os << "Savings Account Balance: " << acc.balance << " Interest Rate: " << acc.intRate;

    return os;
}
