#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"


class SavingsAccount : public Account {
        friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &acc);
    protected:
        double intRate;
    public:
        SavingsAccount();
        SavingsAccount(double balance, double intRate);
        void deposit(double amount);
};


#endif
