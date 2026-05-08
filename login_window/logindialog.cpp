#include "logindialog.h"

#include <QApplication>
#include <QDialogButtonBox>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScreen>
#include <QVBoxLayout>
#include <QFormLayout>

LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent)
{
    buildUi();
}

QString LoginDialog::loggedInUser() const
{
    return m_loggedInUser;
}

void LoginDialog::buildUi()
{
    setObjectName("LoginDialog");
    setWindowTitle("MediQueue Pro");
    setFixedSize(560, 620);
    if (QScreen* screen = QApplication::primaryScreen()) {
        const QRect available = screen->availableGeometry();
        move(available.center() - rect().center());
    }

    setStyleSheet(
        "QDialog#LoginDialog {"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1462f3, stop:1 #3627b9);"
        "}"
        "QFrame#Card {"
        "  background: white;"
        "  border-radius: 18px;"
        "}"
        "QLabel {"
        "  color: #111827;"
        "  font-family: Segoe UI;"
        "}"
        "QLabel#Title {"
        "  font-size: 23px;"
        "  font-weight: 700;"
        "}"
        "QLabel#Subtitle, QLabel#Footer {"
        "  color: #5b6472;"
        "  font-size: 12px;"
        "}"
        "QLabel#FieldLabel {"
        "  font-size: 12px;"
        "  font-weight: 600;"
        "}"
        "QLineEdit {"
        "  min-height: 38px;"
        "  border: 1px solid #d6dbe3;"
        "  border-radius: 8px;"
        "  padding: 0 12px;"
        "  font-size: 13px;"
        "  background-color: white"
        "  color: black;"
        "}"
        "QLineEdit:focus {"
        "  border: 1px solid #1f66f2;"
        "}"
        "QPushButton#PrimaryButton {"
        "  min-height: 38px;"
        "  border: none;"
        "  border-radius: 8px;"
        "  color: white;"
        "  font-size: 13px;"
        "  font-weight: 700;"
        "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #1d6cf4, stop:1 #0d47e8);"
        "}"
        "QPushButton#PrimaryButton:hover {"
        "  background: #155be2;"
        "}"
        "QPushButton#LinkButton {"
        "  border: none;"
        "  color: #1155c8;"
        "  font-weight: 700;"
        "  background: transparent;"
        "}"
        "QFrame#DemoBox {"
        "  background: #eef6ff;"
        "  border: 1px solid #cfe1f5;"
        "  border-radius: 8px;"
        "}"
        "QLabel#Message {"
        "  min-height: 20px;"
        "  font-size: 12px;"
        "}"
    );

    QVBoxLayout* pageLayout = new QVBoxLayout(this);
    pageLayout->setContentsMargins(50, 30, 50, 26);
    pageLayout->setSpacing(10);

    QFrame* card = new QFrame(this);
    card->setObjectName("Card");
    card->setFixedWidth(360);

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(card);
    shadow->setBlurRadius(30);
    shadow->setOffset(0, 14);
    shadow->setColor(QColor(15, 23, 42, 70));
    card->setGraphicsEffect(shadow);

    QVBoxLayout* cardLayout = new QVBoxLayout(card);
    cardLayout->setContentsMargins(28, 22, 28, 20);
    cardLayout->setSpacing(9);

    QLabel* icon = new QLabel("+", card);
    icon->setAlignment(Qt::AlignCenter);
    icon->setFixedSize(48, 48);
    icon->setStyleSheet(
        "background:#145de8; color:white; border-radius:12px;"
        "font-size:28px; font-weight:800;"
    );
    cardLayout->addWidget(icon, 0, Qt::AlignHCenter);

    QLabel* title = new QLabel("MediQueue Pro", card);
    title->setObjectName("Title");
    title->setAlignment(Qt::AlignCenter);
    cardLayout->addWidget(title);

    QLabel* subtitle = new QLabel("Sign in to manage your patient queue", card);
    subtitle->setObjectName("Subtitle");
    subtitle->setAlignment(Qt::AlignCenter);
    cardLayout->addWidget(subtitle);

    QLabel* emailLabel = new QLabel("Email Address", card);
    emailLabel->setObjectName("FieldLabel");
    cardLayout->addWidget(emailLabel);

    m_emailInput = new QLineEdit(card);
    m_emailInput->setPlaceholderText("doctor@hospital.com");
    m_emailInput->setClearButtonEnabled(true);
    cardLayout->addWidget(m_emailInput);

    QLabel* passwordLabel = new QLabel("Password", card);
    passwordLabel->setObjectName("FieldLabel");
    cardLayout->addWidget(passwordLabel);

    m_passwordInput = new QLineEdit(card);
    m_passwordInput->setPlaceholderText("Enter your password");
    m_passwordInput->setEchoMode(QLineEdit::Password);
    cardLayout->addWidget(m_passwordInput);

    QPushButton* signInButton = new QPushButton("Sign In", card);
    signInButton->setObjectName("PrimaryButton");
    cardLayout->addWidget(signInButton);
    connect(signInButton, &QPushButton::clicked, this, &LoginDialog::attemptLogin);
    connect(m_passwordInput, &QLineEdit::returnPressed, this, &LoginDialog::attemptLogin);

    m_messageLabel = new QLabel(card);
    m_messageLabel->setObjectName("Message");
    m_messageLabel->setAlignment(Qt::AlignCenter);
    cardLayout->addWidget(m_messageLabel);

    QFrame* demoBox = new QFrame(card);
    demoBox->setObjectName("DemoBox");
    QVBoxLayout* demoLayout = new QVBoxLayout(demoBox);
    demoLayout->setContentsMargins(12, 9, 12, 9);
    QLabel* demoText = new QLabel("Demo Credentials:\nEmail: demo@hospital.com\nPassword: demo123", demoBox);
    demoText->setWordWrap(true);
    demoText->setMinimumHeight(42);
    demoText->setStyleSheet("color:#173f68; font-size:9px;");
    demoLayout->addWidget(demoText);
    cardLayout->addWidget(demoBox);

    QHBoxLayout* signupLayout = new QHBoxLayout();
    signupLayout->setAlignment(Qt::AlignCenter);
    QLabel* signupText = new QLabel("Don't have an account?", card);
    signupText->setObjectName("Subtitle");
    QPushButton* signupButton = new QPushButton("Sign up", card);
    signupButton->setObjectName("LinkButton");
    signupLayout->addWidget(signupText);
    signupLayout->addWidget(signupButton);
    cardLayout->addLayout(signupLayout);
    connect(signupButton, &QPushButton::clicked, this, &LoginDialog::showSignupDialog);

    pageLayout->addWidget(card, 0, Qt::AlignHCenter);

    QLabel* footer = new QLabel("Trusted by healthcare professionals worldwide", this);
    footer->setObjectName("Footer");
    footer->setAlignment(Qt::AlignCenter);
    footer->setStyleSheet("color: white;");
    pageLayout->addWidget(footer);
}

void LoginDialog::attemptLogin()
{
    const QString email = m_emailInput->text().trimmed();
    const QString password = m_passwordInput->text();

    QString error;
    if (!m_auth.login(email, password, &error)) {
        showMessage(error, true);
        return;
    }

    m_loggedInUser = email;
    accept();
}

void LoginDialog::showSignupDialog()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Create Account");

    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    QFormLayout* form = new QFormLayout();
    QLineEdit* emailInput = new QLineEdit(&dialog);
    QLineEdit* passwordInput = new QLineEdit(&dialog);
    passwordInput->setEchoMode(QLineEdit::Password);
    form->addRow("Email", emailInput);
    form->addRow("Password", passwordInput);
    layout->addLayout(form);

    QLabel* message = new QLabel(&dialog);
    message->setStyleSheet("color:#b42318;");
    layout->addWidget(message);

    QDialogButtonBox* buttons = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel, &dialog);
    layout->addWidget(buttons);

    connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    connect(buttons, &QDialogButtonBox::accepted, [&]() {
        QString error;
        if (m_auth.registerUser(emailInput->text().trimmed(), passwordInput->text(), &error)) {
            m_emailInput->setText(emailInput->text().trimmed());
            showMessage("Account created. You can sign in now.", false);
            dialog.accept();
        } else {
            message->setText(error);
        }
    });

    dialog.exec();
}

void LoginDialog::showMessage(const QString& message, bool isError)
{
    m_messageLabel->setText(message);
    m_messageLabel->setStyleSheet(isError ? "color:#b42318;" : "color:#067647;");
}
