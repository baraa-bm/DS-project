#include "user.h"

// default constructor
User::User() : username("admin"), password("admin") {}

// parameterized constructor
User::User(std::string uname, std::string pwd) : username(uname), password(pwd) {}

// returns the username
std::string User::getUsername() const {
    return username;
}

// checks if the provided password matches the stored password
bool User::authenticate(std::string inputPwd) const {
    return password == inputPwd;
}

// allows changing the password securely
void User::setPassword(std::string newPwd) {
    password = newPwd;
}
