#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "Customer.h"
#include "Admin.h"
#include "Account.h"
#include <vector>
#include <string>

class BankSystem
{
private:
    std::vector<Customer> customers;
    std::vector<Admin> admins;
    std::vector<Account> accounts;

public:
    BankSystem();
    ~BankSystem(); // Added destructor

    // Load and save data
    void loadCustomersFromFile(const std::string &filename);
    void loadAdminsFromFile(const std::string &filename);
    void loadAccountsFromFile(const std::string &filename);
    void saveCustomersToFile(const std::string &filename) const;
    void saveAdminsToFile(const std::string &filename) const;
    void saveAccountsToFile(const std::string &filename) const;

    // User management
    void addCustomer(const Customer &customer);
    void addAdmin(const Admin &admin);

    // Authentication
    Customer *loginCustomer(const std::string &username, const std::string &password);
    Admin *loginAdmin(const std::string &username, const std::string &password);

    // Admin features
    void deleteCustomer(const std::string &userName);
    void viewAllCustomers() const;

    // Account operations
    bool depositToAccount(Account *acc, double amount);
    bool withdrawFromAccount(Account *acc, double amount);

    Account *findAccByAccNo(const std::string &accountNumber);
};

#endif // BANKSYSTEM_H
