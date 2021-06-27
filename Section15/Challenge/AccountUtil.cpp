#include <iostream>
#include "AccountUtil.h"

// Helper functions for Account class

// Displays Account objects in a vector of Account objects
void display(const std::vector<Account> &acc) {
    std::cout << "\n=====Accounts=====" << std::endl;

    for (const auto &acc1 : acc) {
        std::cout << acc1 << std::endl;
    }
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account> &acc, double amount) {
    std::cout << "\n=====Depositing to Accounts=====" << std::endl;

    for (auto &acc1 : acc) {
        if (acc1.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << acc1 << std::endl;
        }
        else {
            std::cout << "Failed Deposit of " << amount << " to " << acc1 << std::endl; 
        }
    }
}

// Withdraw amount of each Amount object in the vector
void withdraw(std::vector<Account> &acc, double amount) {
    std::cout << "\n=====Withdrawing from Accounts=====" << std::endl;

    for (auto &acc1 : acc) {
        if (acc1.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << acc1 << std::endl;
        }
        else {
            std::cout << "Failed withdrew " << amount << " from " << acc1 << std::endl;
        }
    }
}


// Helper functions for Savings Account class

// Displays Savings Account objects in a vector of Savings Account objects
void display(const std::vector<SavingsAccount> &acc) {
    std::cout << "\n=====Savings Accounts=====" << std::endl;

    for (const auto &acc1 : acc) {
        std::cout << acc1 << std::endl;
    }
}

// Deposits supplied amount to each Savings Account object in the vector
void deposit(std::vector<SavingsAccount> &acc, double amount) {
    std::cout << "\n=====Depositing to Savings Acounts=====" << std::endl;

    for (auto &acc1 : acc) {
        if (acc1.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << acc1 << std::endl;
        }
        else {
            std::cout << "Failed Deposit of " << amount << " to " << acc1 << std::endl; 
        }
    }
}

// Withdraw suplied amount from each Savings Account object in the vector
void withdraw(std::vector<SavingsAccount> &acc, double amount) {
    std::cout << "\n=====Withdrawing from Savings Accounts=====" << std::endl;

    for (auto &acc1 : acc) {
        if (acc1.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << acc1 << std::endl;
        }
        else {
            std::cout << "Failed withdrawal " << amount << " from " << acc1 << std::endl;
        }
    }
}


// Helper functions for Checking Account class

// Displays Checking Account objects in a vector of Checking Account objects
void display(const std::vector<CheckingAccount> &acc) {
    std::cout << "\n=====Checking Account=====" << std::endl;

    for (const auto &acc1 : acc) {
        std::cout << acc1 << std::endl;
    }
}

// Deposits supplied amount to each Checking Account object in the vector
void deposit(std::vector<CheckingAccount> &acc, double amount) {
    std::cout << "\n=====Depositing to Checking Acounts=====" << std::endl;

    for (auto &acc1 : acc) {
        if (acc1.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << acc1 << std::endl;
        }
        else {
            std::cout << "Failed Deposit of " << amount << " to " << acc1 << std::endl; 
        }
    }
}

// Withdraw suplied amount from each Checking Account object in the vector
void withdraw(std::vector<CheckingAccount> &acc, double amount) {
    std::cout << "\n=====Withdrawing from Checking Accounts=====" << std::endl;

    for (auto &acc1 : acc) {
        if (acc1.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << acc1 << std::endl;
        }
        else {
            std::cout << "Failed withdrawal " << amount << " from " << acc1 << std::endl;
        }
    }
}


// Helper functions for Trust Account class

// Displays Trust Account objects in a vector of Trust Account objects
void display(const std::vector<TrustAccount> &acc) {
    std::cout << "\n=====Trust Account=====" << std::endl;

    for (const auto &acc1 : acc) {
        std::cout << acc1 << std::endl;
    }
}

// Deposits supplied amount to each Trust Account object in the vector
void deposit(std::vector<TrustAccount> &acc, double amount) {
    std::cout << "\n=====Depositing to Trust Acounts=====" << std::endl;

    for (auto &acc1 : acc) {
        if (acc1.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << acc1 << std::endl;
        }
        else {
            std::cout << "Failed Deposit of " << amount << " to " << acc1 << std::endl; 
        }
    }
}

// Withdraw suplied amount from each Trust Account object in the vector
void withdraw(std::vector<TrustAccount> &acc, double amount) {
    std::cout << "\n=====Withdrawing from Trust Accounts=====" << std::endl;

    for (auto &acc1 : acc) {
        if (acc1.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << acc1 << std::endl;
        }
        else {
            std::cout << "Failed withdrawal " << amount << " from " << acc1 << std::endl;
        }
    }
}
