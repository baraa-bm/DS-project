#ifndef LOGIN_WINDOW_LOGINDIALOG_H
#define LOGIN_WINDOW_LOGINDIALOG_H

#include "userauth.h"

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    explicit LoginDialog(QWidget* parent = nullptr);
    QString loggedInUser() const;

private slots:
    void attemptLogin();
    void showSignupDialog();

private:
    void buildUi();
    void showMessage(const QString& message, bool isError);

    UserAuth m_auth;
    QString m_loggedInUser;
    QLineEdit* m_emailInput = nullptr;
    QLineEdit* m_passwordInput = nullptr;
    QLabel* m_messageLabel = nullptr;
};

#endif
