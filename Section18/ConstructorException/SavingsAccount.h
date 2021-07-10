#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"


class SavingsAccount : public Account {
    private:
        static constexpr const char *def_name = "Unnamed Savings Account";
        static constexpr double def_balance = 0.0;
        static constexpr double def_int_rate = 0.0;
    protected:
        double int_rate;
    public:
        SavingsAccount(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
        virtual bool withdraw(double amount) override;
        virtual bool deposit(double amount) override;
        virtual void print(std::ostream &os) const override;
        virtual ~SavingsAccount() = default;
};


#endif
