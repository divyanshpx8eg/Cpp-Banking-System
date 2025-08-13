// include/User.h
#ifndef USER_H // means if USER_H not defined then run till #endif else don't run it (it is used to run this class one time only)
#define USER_H

#include <string>

class User
{
protected:
    std::string username; // Must Be Unique
    std::string password;
    std::string role; // "customer" or "admin"

public:
    User();
    User(const std::string &username,
         const std::string &password, const std::string &role);

    // Getters
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getRole() const;

    // Setters
    void setUsername(const std::string &username);
    void setPassword(const std::string &password);
    void setRole(const std::string &role);

    // Authentication
    bool authenticate(const std::string &enteredPassword) const;

    // Virtual destructor for proper cleanup
    virtual ~User();
};

#endif // USER_H
