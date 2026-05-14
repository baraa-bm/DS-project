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
    setFixedSize(410, 470);
    if (QScreen* screen = QApplication::primaryScreen()) {
        const QRect available = screen->availableGeometry();
        move(available.center() - rect().center());
    }

    QVBoxLayout* pageLayout = new QVBoxLayout(this);
    pageLayout->setContentsMargins(24, 14, 24, 12);
    pageLayout->setSpacing(6);

    QFrame* card = new QFrame(this);
    card->setObjectName("Card");
    card->setFixedWidth(290);

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(card);
    shadow->setBlurRadius(30);
    shadow->setOffset(0, 14);
    shadow->setColor(QColor(15, 23, 42, 70));
    card->setGraphicsEffect(shadow);

    QVBoxLayout* cardLayout = new QVBoxLayout(card);
    cardLayout->setContentsMargins(18, 12, 18, 12);
    cardLayout->setSpacing(5);

    QLabel* icon = new QLabel("+", card);
    icon->setObjectName("LoginIcon");
    icon->setAlignment(Qt::AlignCenter);
    icon->setFixedSize(36, 36);
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
    demoLayout->setContentsMargins(8, 6, 8, 6);
    QLabel* demoText = new QLabel("Demo Credentials:\nEmail: demo@hospital.com\nPassword: demo123", demoBox);
    demoText->setObjectName("DemoText");
    demoText->setWordWrap(true);
    demoText->setMinimumHeight(32);
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
