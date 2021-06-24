#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>

class Account {
        friend std::ostream &operator<<(std::ostream &os, const Account &acc); 
    protected:
        double balance;
    public:
        Account();
        Account(double balance);
        void deposit(double amount);
        void withdraw(double amount);
};


#endif
