#include "../include/Customer.h"
#include <algorithm> // For std::remove

// Default constructor
Customer::Customer() : User(), accountNumber("") {}

// Parameterized constructor
Customer::Customer(const std::string &username,
                   const std::string &password,
                   const std::string &accountNumber)
    : User(username, password, "customer"), accountNumber(accountNumber) {}

// Get list of account IDs
std::string Customer::getAccountNumber() const
{
    return accountNumber;
}
