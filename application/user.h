#ifndef ADS_PROJECT_USER_H
#define ADS_PROJECT_USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    // constructors
    User();
    User(std::string uname, std::string pwd);

    // getters and functionality
    std::string getUsername() const;
    bool authenticate(std::string inputPwd) const;

    // setters
    void setPassword(std::string newPwd);
};

#endif //ADS_PROJECT_USER_H
