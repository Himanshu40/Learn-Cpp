#include "CheckingAccount.h"


CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account {name, balance}, withdrawFee {1.50} {
}

bool CheckingAccount::withdraw(double amount) {
    amount += withdrawFee;

    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &acc) {
    os << "[Checking Account: " << acc.name << ", " << acc.balance << ", $ " << acc.withdrawFee << "]";

    return os;
}
