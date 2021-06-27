#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_

#include "Account.h"


class SavingsAccount : public Account {
    private:
        static constexpr const char *defName = "Unnamed Savings Account";
        static constexpr double defBalance = 0.0;
        static constexpr double defIntRate = 0.0;
        friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &acc);
    protected:
        double intRate;
    public:
        SavingsAccount(std::string name = defName, double balance = defBalance, double intRate = defIntRate);
        bool deposit(double amount);
};


#endif
