#include "userauth.h"

#include "../application/user.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>

namespace {

QString defaultUsersPath()
{
    // Keep users.txt next to the exe.
    // This is the file the app will really use when it runs.
    return QCoreApplication::applicationDirPath() + "/users.txt";
}

bool makeUsersFileIfMissing(const QString& path)
{
    // If users.txt already exists, everything is fine.
    if (QFile::exists(path)) {
        return true;
    }

    // Make sure the folder exists.
    QDir folder(QCoreApplication::applicationDirPath());
    if (!folder.exists()) {
        return false;
    }

    // Create a fresh users.txt file with the demo account.
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out << "demo@hospital.com demo123\n";
    file.close();
    return true;
}

}

UserAuth::UserAuth(QString usersFilePath)
    : m_usersFilePath(usersFilePath.isEmpty() ? defaultUsersPath() : usersFilePath)
{
    // Create users.txt as soon as UserAuth is made.
    makeUsersFileIfMissing(m_usersFilePath);
}

bool UserAuth::login(const QString& username, const QString& password, QString* error) const
{
    // Make sure the file exists before reading.
    if (!makeUsersFileIfMissing(m_usersFilePath)) {
        if (error) {
            *error = "Could not create users.txt at:\n" + m_usersFilePath;
        }
        return false;
    }

    QFile file(m_usersFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (error) {
            *error = "Could not open users.txt at:\n" + m_usersFilePath;
        }
        return false;
    }

    QTextStream in(&file);

    // Read one username and one password at a time.
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

    // Make sure the file exists before reading or writing.
    if (!makeUsersFileIfMissing(m_usersFilePath)) {
        if (error) {
            *error = "Could not create users.txt at:\n" + m_usersFilePath;
        }
        return false;
    }

    QFile readFile(m_usersFilePath);
    if (!readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (error) {
            *error = "Could not read users.txt at:\n" + m_usersFilePath;
        }
        return false;
    }

    QTextStream in(&readFile);

    // Do not allow the same account twice.
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
            *error = "Could not write to users.txt at:\n" + m_usersFilePath;
        }
        return false;
    }

    QTextStream out(&writeFile);

    // Save the new account on a new line.
    out << cleanUsername << ' ' << password << '\n';
    writeFile.close();

    return true;
}

QString UserAuth::usersFilePath() const
{
    return m_usersFilePath;
}
