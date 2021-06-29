#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>


class Account {
    private:
        static constexpr const char *defName    = "Unnamed Account";
        static constexpr double      defBalance = 0.0;
        friend std::ostream &operator<<(std::ostream &os, const Account &acc);
    protected:
        std::string name;
        double      balance;
    public:
        Account(std::string name = defName, double balance = defBalance);
        bool   deposit(double amount);
        bool   withdraw(double amount);
        double getBalance() const;
};


#endif
