#include "../include/Account.h"

// Constructor
Account::Account() : accountNumber(""), balance(0.0) {}
Account::Account(const std::string &accountNumber, double balance)
    : accountNumber(accountNumber), balance(balance) {}

// Getters
std::string Account::getAccountNumber() const
{
    return accountNumber;
}

double Account::getBalance() const
{
    return balance;
}

// Setters
void Account::setBalance(double newBalance)
{
    balance = newBalance;
}

// Deposit money
bool Account::deposit(double amount)
{
    if (amount <= 0)
        return false;
    balance += amount;
    return true;
}

// Withdraw money
bool Account::withdraw(double amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        return true;
    }
    return false;
}
