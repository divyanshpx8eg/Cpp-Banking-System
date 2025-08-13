# 🏦 Bank Management System (C++)

## 📌 Overview

The **Bank Management System** is a console-based C++ application that allows **customers** to manage their bank accounts and **admins** to manage customer data.  
It uses file storage for data persistence and demonstrates key **Object-Oriented Programming (OOP)** concepts.

---

## ✨ Features

### 👤 Customer

- **Secure Login** – Login with username and password.
- **View Balance** – Check current account balance.
- **Deposit Funds** – Add money to your account.
- **Withdraw Funds** – Withdraw money if you have enough balance.

### 🛠️ Admin

- **Secure Login** – Admin-only access.
- **View All Customers** – See all registered customers and their accounts.
- **Delete Customer** – Remove a customer and their account from the system.

---

## 🛠️ Technologies Used

- **Language:** C++17
- **Concepts:**
  - Classes & Objects
  - Inheritance (`User` → `Customer` / `Admin`)
  - Encapsulation with getters & setters
  - File I/O for saving and loading data
  - Basic input validation

---

## 📂 Project Structure

```plaintext

project/
│── include/ # Header files
│ ├── BankSystem.h
│ ├── Account.h
│ ├── User.h
│ ├── Customer.h
│ └── Admin.h
│
│── src/ # Implementation files
│ ├── BankSystem.cpp
│ ├── Account.cpp
│ ├── User.cpp
│ ├── Customer.cpp
│ └── Admin.cpp
│
│── data/ # Data storage files
│ ├── customer.txt
│ ├── admin.txt
│ └── account.txt
│
└── main.cpp # Application entry point
```

---

## ⚙️ Compilation & Execution

### **Compile**

```bash
g++ main.cpp src/*.cpp -I include -o BankSystem

./BankSystem   # Linux/Mac
.\BankSystem   # Windows
```
