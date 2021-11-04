#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"


class CheckingAccount: public Account {
    private:
        static constexpr const char *def_name = "Unnamed Checking Account";
        static constexpr double def_balance = 0.0;
        static constexpr double per_check_fee = 1.5;
    public:
        CheckingAccount(std::string name = def_name, double balance = def_balance);    
        virtual bool withdraw(double amount) override;
        virtual bool deposit(double amount) override;
        virtual void print(std::ostream &os) const override;
        virtual ~CheckingAccount() = default;
};


#endif
