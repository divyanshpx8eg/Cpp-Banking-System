// include/Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
private:
    std::string accountNumber;
    double balance;

public:
    Account();
    Account(const std::string &accountNumber, double balance);

    // Getters
    std::string getAccountNumber() const;
    double getBalance() const;

    // Setters
    void setBalance(double newBalance);

    // Operations
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // ACCOUNT_H
