#include "userauth.h"

#include "../application/user.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>

namespace {
QString defaultUsersPath()
{
    #ifdef MEDIQUEUE_USERS_FILE
    const QString projectUsersFile = QString::fromUtf8(MEDIQUEUE_USERS_FILE);
    if (!projectUsersFile.isEmpty()) {
        return projectUsersFile;
    }
    #endif

    const QString workingCopy = QDir::current().absoluteFilePath("users.txt");
    if (QFile::exists(workingCopy)) {
        return workingCopy;
    }

    const QString exeCopy = QCoreApplication::applicationDirPath() + "/users.txt";
    if (QFile::exists(exeCopy)) {
        return exeCopy;
    }

    return workingCopy;
}
}

UserAuth::UserAuth(QString usersFilePath)
    : m_usersFilePath(usersFilePath.isEmpty() ? defaultUsersPath() : usersFilePath)
{
}

bool UserAuth::login(const QString& username, const QString& password, QString* error) const
{
    QFile file(m_usersFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (error) {
            *error = "Could not open users.txt.";
        }
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString storedUsername;
        QString storedPassword;
        in >> storedUsername >> storedPassword;

        if (storedUsername.isEmpty()) {
            continue;
        }

        User user(storedUsername.toStdString(), storedPassword.toStdString());
        if (storedUsername == username && user.authenticate(password.toStdString())) {
            return true;
        }
    }

    if (error) {
        *error = "Incorrect email or password.";
    }
    return false;
}

bool UserAuth::registerUser(const QString& username, const QString& password, QString* error) const
{
    if (username.trimmed().isEmpty() || password.isEmpty()) {
        if (error) {
            *error = "Email and password are required.";
        }
        return false;
    }

    QFile readFile(m_usersFilePath);
    if (readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&readFile);
        while (!in.atEnd()) {
            QString storedUsername;
            QString storedPassword;
            in >> storedUsername >> storedPassword;
            if (storedUsername == username) {
                if (error) {
                    *error = "This account already exists.";
                }
                return false;
            }
        }
    }

    QFile writeFile(m_usersFilePath);
    if (!writeFile.open(QIODevice::Append | QIODevice::Text)) {
        if (error) {
            *error = "Could not write to users.txt.";
        }
        return false;
    }

    QTextStream out(&writeFile);
    out << username << ' ' << password << '\n';
    return true;
}

QString UserAuth::usersFilePath() const
{
    return m_usersFilePath;
}
