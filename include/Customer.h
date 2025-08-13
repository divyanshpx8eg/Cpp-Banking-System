#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <string>
#include <vector>

class Customer : public User
{
private:
    std::string accountNumber;

public:
    // Constructors
    Customer();
    Customer(const std::string &username,
             const std::string &password,
             const std::string &accountNumber);

    // Getters
    std::string getAccountNumber() const;
};

#endif // CUSTOMER_H
