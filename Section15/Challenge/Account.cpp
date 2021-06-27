#include "Account.h"


Account::Account(std::string name, double balance) : name {name}, balance {balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    }
    else {
        balance += amount;
        
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance -  amount >= 0) {
        balance -= amount;

        return true;
    }
    else {
        return false;
    }
}

double Account::getBalance() const {
    return balance;
}

std::ostream &operator<<(std::ostream &os, const Account &acc) {
    os << "[Account: " << acc.name << ", " << acc.balance << "]";

    return os;
}
