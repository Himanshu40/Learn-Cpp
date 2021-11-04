#include "TrustAccount.h"


TrustAccount::TrustAccount(std::string name, double balance, double int_rate)
    : SavingsAccount {name, balance, int_rate}, num_withdrawals {0}  {
}

// Deposit additional $50 bonus when amount >= $5000
bool TrustAccount::deposit(double amount) {
    if (amount >= bonus_threshold) {
        amount += bonus_amount;
    }
    
    return SavingsAccount::deposit(amount);
}
    
// Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool TrustAccount::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent)) {
        return false;
    }
    else {
        ++num_withdrawals;

        return SavingsAccount::withdraw(amount);
    }
}

void TrustAccount::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Trust Account: " << name << ", " << balance
       << ", " << int_rate << "%, withdrawals: " << num_withdrawals << "]";
}
