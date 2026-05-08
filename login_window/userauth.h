#ifndef LOGIN_WINDOW_USERAUTH_H
#define LOGIN_WINDOW_USERAUTH_H

#include <QString>

class UserAuth {
public:
    explicit UserAuth(QString usersFilePath = QString());

    bool login(const QString& username, const QString& password, QString* error = nullptr) const;
    bool registerUser(const QString& username, const QString& password, QString* error = nullptr) const;
    QString usersFilePath() const;

private:
    QString m_usersFilePath;
};

#endif
