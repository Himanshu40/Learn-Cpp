#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_

#include "Account.h"


class SavingsAccount : public Account {
    public:
        SavingsAccount();
        ~SavingsAccount();

        double intRate;

        void deposit(double amount);
        void withdraw(double amount);
};


#endif
