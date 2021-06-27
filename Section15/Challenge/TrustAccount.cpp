#include "TrustAccount.h"


TrustAccount::TrustAccount(std::string name, double balance, double intRate)
    : SavingsAccount {name, balance, intRate}, withdrawalTimes {0} {
}

bool TrustAccount::deposit(double amount) {
    if (amount >= bonusThreshold) {
        amount += bonusAmount;
    }
    
    return SavingsAccount::deposit(amount);
}

bool TrustAccount::withdraw(double amount) {
    if (withdrawalTimes < maxWithdrawals) {
        if (amount <= balance * maxWithdrawPercent) {
            ++withdrawalTimes;
            return Account::withdraw(amount);
        }

        return false;
    }
        
    return false;
}

std::ostream &operator<<(std::ostream &os, const TrustAccount &acc) {
    os << "[Trust Account: " << acc.name << ", " << acc.balance << ", " << acc.intRate
       << "%, withdrawals: " << acc.withdrawalTimes << "]";

    return os;
}
