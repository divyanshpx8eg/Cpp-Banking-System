#include "../include/User.h"

// Default constructor
User::User() : username(""), password(""), role("") {}

// Parameterized constructor
User::User(const std::string &username,
           const std::string &password, const std::string &role)
    : username(username), password(password), role(role) {}

// Destructor
User::~User() {}

// Getter

std::string User::getUsername() const
{
    return username;
}

std::string User::getPassword() const
{
    return password;
}

std::string User::getRole() const
{
    return role;
}

// Setters
void User::setUsername(const std::string &username)
{
    this->username = username;
}

void User::setPassword(const std::string &password)
{
    this->password = password;
}

void User::setRole(const std::string &role)
{
    this->role = role;
}

// Simple password authentication
bool User::authenticate(const std::string &enteredPassword) const
{
    return password == enteredPassword;
}
