#include "CheckingAccount.h"


CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account {name, balance} {
}

bool CheckingAccount::withdraw(double amount) {
    amount += perCheckFee;

    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &acc) {
    os << "[Checking Account: " << acc.name << ", " << acc.balance << ", $ " << acc.perCheckFee << "]";

    return os;
}
