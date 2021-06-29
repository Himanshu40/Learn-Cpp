#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_

#include "SavingsAccount.h"


class TrustAccount : public SavingsAccount {
    private:
        static constexpr const char *defName            = "Unnamed Trust Account";
        static constexpr double      defBalance         = 0.0;
        static constexpr double      defIntRate         = 0.0;
        static constexpr double      bonusAmount        = 50.0;
        static constexpr double      bonusThreshold     = 5000.00;
        static constexpr double      maxWithdrawPercent = 0.2;
        static constexpr int         maxWithdrawals     = 3;
        friend std::ostream &operator<<(std::ostream &os, const TrustAccount &acc);
    protected:
        int withdrawalTimes;
    public:
        TrustAccount(std::string name = defName, double balance = defBalance, double intRate = defIntRate);
        bool deposit(double amount);
        bool withdraw(double amount);
};


#endif
