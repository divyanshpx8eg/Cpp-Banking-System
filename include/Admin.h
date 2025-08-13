// include/Admin.h
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <string>

class Admin : public User
{
public:
    Admin();
    Admin(const std::string &username,
          const std::string &password);

    // Admin-specific actions can go here (placeholders for now)
    void viewAllAccounts();                             // Stub for viewing accounts
    void deleteCustomer(const std::string &customerID); // Stub for deleting user
};

#endif // ADMIN_H
