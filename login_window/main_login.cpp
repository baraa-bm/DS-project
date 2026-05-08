// #include "logindialog.h"

// #include "../mainwindow.h"

// #include <QApplication>
// #include <QFile>

// int main(int argc, char* argv[])
// {
//     QApplication app(argc, argv);

//     QFile styleFile(":/style.qss");
//     if (styleFile.open(QFile::ReadOnly)) {
//         app.setStyleSheet(QLatin1String(styleFile.readAll()));
//     }

//     LoginDialog login;
//     if (login.exec() != QDialog::Accepted) {
//         return 0;
//     }

//     MainWindow window;
//     window.showFullScreen();
//     return app.exec();
// }
