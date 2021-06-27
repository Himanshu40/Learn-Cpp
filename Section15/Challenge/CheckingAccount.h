#ifndef _CHECKINGACCOUNT_H_
#define _CHECKINGACCOUNT_H_

#include "Account.h"

class CheckingAccount : public Account {
    private:
        static constexpr const char *defName = "Unnamed Checking Account";
        static constexpr double defBalance = 0.0;
        static constexpr double perCheckFee = 1.5;
        friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &acc);
    public:
        CheckingAccount(std::string name = defName, double balance = defBalance);
        bool withdraw(double amount);
};


#endif
