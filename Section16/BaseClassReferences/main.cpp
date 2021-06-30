#include <iostream>

using namespace std;

class Account {
    public:
        virtual void withdraw(double amount) {
            cout << "In Account::withdraw" << endl;
        }

        virtual ~Account() {}
};

class Savings : public Account {
    public:
        virtual void withdraw(double amount) {
            cout << "In Savings::withdraw" << endl;
        }

        virtual ~Savings() {}
};

class Checking : public Account {
    public:
        virtual void withdraw(double amount) {
            cout << "In Checking::withdraw" << endl;
        }

        virtual ~Checking() {}
};

class Trust : public Account {
    public:
        virtual void withdraw(double amount) {
            cout << "In Trust::withdraw" << endl;
        }

        virtual ~Trust() {}
};


void doWithdraw(Account &acc, double amount) {
    acc.withdraw(amount);
}

int main() {
    Account a;
    Account &ref = a;
    ref.withdraw(1000);     // Account::withdraw

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);    // Trust::withdraw

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    doWithdraw(a1, 1000);   // Account::withdraw
    doWithdraw(a2, 2000);   // Savings::withdraw
    doWithdraw(a3, 3000);   // Checking::withdraw
    doWithdraw(a4, 4000);   // Trust::withdraw

    return 0;
}
