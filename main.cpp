#include <iostream>
#include <limits>
#include "include/BankSystem.h"

void customerMenu(BankSystem &bank, Customer *customer)
{
    std::cout << "\nWelcome, " << customer->getUsername() << "!\n";

    while (true)
    {
        std::cout << "\nCustomer Menu:\n";
        std::cout << "Your Account:\n";
        std::string accountNumber = customer->getAccountNumber();
        Account *selectedAccount = bank.findAccByAccNo(accountNumber);
        std::cout << "Account Number: " << accountNumber
                  << " | Balance: ₹" << selectedAccount->getBalance() << '\n';

        std::cout << "\n1. View Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Logout\n";
        std::cout << "Enter choice: ";

        int action;
        std::cin >> action;

        switch (action)
        {
        case 1:
            std::cout << "Balance: ₹" << selectedAccount->getBalance() << '\n';
            break;
        case 2:
        {
            double amount;
            std::cout << "Enter deposit amount: ₹";
            std::cin >> amount;
            bank.depositToAccount(selectedAccount, amount);
            std::cout << "Deposit successful.\n";
            break;
        }
        case 3:
        {
            double amount;
            std::cout << "Enter withdrawal amount: ₹";
            std::cin >> amount;
            if (bank.withdrawFromAccount(selectedAccount, amount))
                std::cout << "Withdrawal successful.\n";
            else
                std::cout << "Insufficient balance.\n";
            break;
        }
        case 4:
            return;
        default:
            std::cout << "Invalid option.\n";
        }
    }
}

void adminMenu(BankSystem &bank, Admin *admin)
{
    std::cout << "\nWelcome, Admin " << admin->getUsername() << "!\n";
    while (true)
    {
        std::cout << "\nAdmin Menu:\n";
        std::cout << "1. View All Customers\n";
        std::cout << "2. Delete Customer\n";
        std::cout << "3. Logout\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 3)
            break;

        switch (choice)
        {
        case 1:
            bank.viewAllCustomers();
            break;

        case 2:
        {
            std::string userNameToBeDeleted;
            std::cout << "Enter customer ID to delete: ";
            std::cin >> userNameToBeDeleted;
            bank.deleteCustomer(userNameToBeDeleted);
            std::cout << "Customer deleted if found.\n";
            break;
        }

        default:
            std::cout << "Invalid option.\n";
        }
    }
}

int main()
{
    BankSystem bank;

    // Load existing data
    bank.loadCustomersFromFile("data/customer.txt");
    bank.loadAccountsFromFile("data/account.txt");
    bank.loadAdminsFromFile("data/admin.txt");
    while (true)
    {
        std::cout << "\n==== BANKING SYSTEM ====\n";
        std::cout << "1. Customer Login\n";
        std::cout << "2. Admin Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 3)
            break;

        std::string username, password;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        if (choice == 1)
        {
            Customer *customer = bank.loginCustomer(username, password);
            if (customer)
                customerMenu(bank, customer);
            else
                std::cout << "Invalid customer credentials.\n";
        }
        else if (choice == 2)
        {
            Admin *admin = bank.loginAdmin(username, password);
            if (admin)
                adminMenu(bank, admin);
            else
                std::cout << "Invalid admin credentials.\n";
        }
        else
        {
            std::cout << "Invalid option.\n";
        }
    }

    // Save updated data
    bank.saveCustomersToFile("data/customer.txt");
    bank.saveAdminsToFile("data/admin.txt");
    bank.saveAccountsToFile("data/account.txt");

    std::cout << "Goodbye!\n";
    return 0;
}
