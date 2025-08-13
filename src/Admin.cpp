#include "../include/Admin.h"

// Constructor
Admin::Admin() : User("", "", "admin") {}
Admin::Admin(const std::string &username,
             const std::string &password)
    : User(username, password, "admin") {} // Calls base User constructor
