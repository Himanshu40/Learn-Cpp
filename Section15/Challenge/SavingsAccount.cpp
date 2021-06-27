#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(std::string name, double balance, double intRate)
    : Account {name, balance}, intRate {intRate} {
}

bool SavingsAccount::deposit(double amount) {
    amount += amount * (intRate / 100);

    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &acc) {
    os << "[Savings Account: " << acc.name << ", " << acc.balance << ", " << acc.intRate << "%]";

    return os;
}
