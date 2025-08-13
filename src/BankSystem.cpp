#include "../include/BankSystem.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

BankSystem::BankSystem() {}

BankSystem::~BankSystem()
{
    // Optional: Save data or cleanup here
}
//

//

//

// User Management

// Add a new customer
void BankSystem::addCustomer(const Customer &customer)
{
    customers.push_back(customer);
}

// Add a new admin
void BankSystem::addAdmin(const Admin &admin)
{
    admins.push_back(admin);
}

Account *BankSystem::findAccByAccNo(const std::string &accountNumber)
{
    for (auto &acc : accounts)
    {
        if (acc.getAccountNumber() == accountNumber)
            return &acc;
    }
    return nullptr;
}
//

//

//

//

// Authentication

// Login for customer
Customer *BankSystem::loginCustomer(const std::string &username, const std::string &password)
{
    for (auto &cust : customers)
    {
        if (cust.getUsername() == username && cust.authenticate(password))
        {
            return &cust;
        }
    }
    return nullptr;
}

// Login for admin
Admin *BankSystem::loginAdmin(const std::string &username, const std::string &password)
{
    for (auto &admin : admins)
    {
        if (admin.getUsername() == username && admin.authenticate(password))
        {
            return &admin;
        }
    }
    return nullptr;
}
//

//

//

//

// Admin Features

// Delete customer by userID
void BankSystem::deleteCustomer(const std::string &userName)
{
    customers.erase(
        std::remove_if(customers.begin(), customers.end(),
                       [&](const Customer &cust)
                       { return cust.getUsername() == userName; }),
        customers.end());
}

// View all customers
void BankSystem::viewAllCustomers() const
{
    std::cout << "---- All Customers ----\n";
    for (const auto &cust : customers)
    {
        std::cout
            << " | Name: " << cust.getUsername() << '\n';
    }
}

//

//

//

// Account Operations

// Deposit money
bool BankSystem::depositToAccount(Account *acc, double amount)
{
    if (acc)
    {
        return acc->deposit(amount);
    }
    return false;
}

// Withdraw money
bool BankSystem::withdrawFromAccount(Account *acc, double amount)
{
    if (acc)
    {
        return acc->withdraw(amount);
    }
    return false;
}

//

//

//

// Load and save Data

// Load customers from file (stub)
void BankSystem::loadCustomersFromFile(const std::string &filename)
{
    // TODO: Implement file I/O
    std::ifstream inFile(filename);

    if (!inFile)
    {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string username, password, role, accountNumber;

        if (iss >> username >> password >> role >> accountNumber)
        {
            customers.emplace_back(username, password, accountNumber);
        }
        else
        {
            std::cerr << "Skipping invalid line: " << line << "\n";
        }
    }

    inFile.close();
}
void BankSystem::loadAdminsFromFile(const std::string &filename)
{
    // TODO: Implement file I/O
    std::ifstream inFile(filename);

    if (!inFile)
    {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string username, password, role;

        if (iss >> username >> password >> role)
        {
            admins.emplace_back(username, password);
        }
        else
        {
            std::cerr << "Skipping invalid line: " << line << "\n";
        }
    }

    inFile.close();
}
// Load accounts from file (stub)
void BankSystem::loadAccountsFromFile(const std::string &filename)
{
    // TODO: Implement file I/O
    std::ifstream inFile(filename);

    if (!inFile)
    {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string accountNumber;
        double deposit;

        if (iss >> accountNumber >> deposit)
        {
            accounts.emplace_back(accountNumber, deposit);
        }
        else
        {
            std::cerr << "Skipping invalid line: " << line << "\n";
        }
    }

    inFile.close();
}

// Save customers to file (stub)
void BankSystem::saveCustomersToFile(const std::string &filename) const
{
    // TODO: Implement file I/O
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    for (const auto &customer : customers)
    {
        outFile << customer.getUsername() << " " << customer.getPassword() << " " << customer.getRole() << " " << customer.getAccountNumber() << "\n";
    }

    outFile.close();
}
void BankSystem::saveAdminsToFile(const std::string &filename) const
{
    // TODO: Implement file I/O
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    for (const auto &admin : admins)
    {
        outFile << admin.getUsername() << " " << admin.getPassword() << " " << admin.getRole() << "\n";
    }

    outFile.close();
}

// Save accounts to file (stub)
void BankSystem::saveAccountsToFile(const std::string &filename) const
{
    // TODO: Implement file I/O
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    for (const auto &account : accounts)
    {
        outFile << account.getAccountNumber() << " " << account.getBalance() << "\n";
    }

    outFile.close();
}
