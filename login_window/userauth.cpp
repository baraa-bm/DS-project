#include "userauth.h"

#include "../application/user.h"

#include <QDir>
#include <QFile>
#include <QTextStream>

namespace {

QString defaultUsersPath()
{
    // Use the normal users.txt in the folder where the app is started.
    return QDir::current().absoluteFilePath("users.txt");
}

bool makeUsersFileIfMissing(const QString& path)
{
    // If users.txt already exists, do nothing.
    if (QFile::exists(path)) {
        return true;
    }

    // If users.txt is missing, create an empty one.
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    file.close();
    return true;
}

}

UserAuth::UserAuth(QString usersFilePath)
    : m_usersFilePath(usersFilePath.isEmpty() ? defaultUsersPath() : usersFilePath)
{
    // Make sure users.txt exists before login or signup.
    makeUsersFileIfMissing(m_usersFilePath);
}

bool UserAuth::login(const QString& username, const QString& password, QString* error) const
{
    // Make sure users.txt exists.
    if (!makeUsersFileIfMissing(m_usersFilePath)) {
        if (error) {
            *error = "Could not create users.txt.";
        }
        return false;
    }

    QFile file(m_usersFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (error) {
            *error = "Could not open users.txt.";
        }
        return false;
    }

    QTextStream in(&file);

    // Read username password pairs from users.txt.
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
    QString cleanUsername = username.trimmed();

    if (cleanUsername.isEmpty() || password.isEmpty()) {
        if (error) {
            *error = "Email and password are required.";
        }
        return false;
    }

    // Make sure users.txt exists.
    if (!makeUsersFileIfMissing(m_usersFilePath)) {
        if (error) {
            *error = "Could not create users.txt.";
        }
        return false;
    }

    QFile readFile(m_usersFilePath);
    if (!readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (error) {
            *error = "Could not read users.txt.";
        }
        return false;
    }

    QTextStream in(&readFile);

    // Do not save the same username twice.
    while (!in.atEnd()) {
        QString storedUsername;
        QString storedPassword;
        in >> storedUsername >> storedPassword;

        if (storedUsername == cleanUsername) {
            if (error) {
                *error = "This account already exists.";
            }
            return false;
        }
    }

    readFile.close();

    QFile writeFile(m_usersFilePath);
    if (!writeFile.open(QIODevice::Append | QIODevice::Text)) {
        if (error) {
            *error = "Could not write to users.txt.";
        }
        return false;
    }

    QTextStream out(&writeFile);

    // Save the new username and password.
    out << cleanUsername << ' ' << password << '\n';
    writeFile.close();

    return true;
}

QString UserAuth::usersFilePath() const
{
    return m_usersFilePath;
}
