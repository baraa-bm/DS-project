/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QFrame *MediQueueFrame;
    QLabel *label;
    QFrame *SimulatorFrame;
    QPushButton *add5m;
    QPushButton *add15m;
    QPushButton *add30m;
    QPushButton *add1h;
    QLabel *TimeSimulator;
    QLabel *label_2;
    QFrame *PatientsFrame;
    QFrame *StatsFrame;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1250, 770);
        QPalette palette;
        QBrush brush(QColor(226, 239, 240, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
        MainWindow->setPalette(palette);
        QFont font;
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setMouseTracking(false);
        MediQueueFrame = new QFrame(MainWindow);
        MediQueueFrame->setObjectName("MediQueueFrame");
        MediQueueFrame->setGeometry(QRect(50, 30, 1161, 121));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush1);
        QBrush brush2(QColor(47, 96, 255, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush2);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush3);
        QBrush brush4(QColor(240, 247, 247, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush4);
        QBrush brush5(QColor(112, 120, 120, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush5);
        QBrush brush6(QColor(150, 160, 160, 255));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush6);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush1);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush3);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush1);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush3);
        QBrush brush7(QColor(225, 240, 240, 255));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush7);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush1);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush4);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush8);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush1);
        QBrush brush9(QColor(0, 0, 0, 127));
        brush9.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush9);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush3);
#endif
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush2);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush3);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush4);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush5);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush6);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush3);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush3);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush7);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush4);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush8);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush9);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush3);
#endif
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush5);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush2);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush3);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush4);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush5);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush6);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush5);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush3);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush5);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush7);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush7);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush1);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush7);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush8);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush1);
        QBrush brush10(QColor(112, 120, 120, 127));
        brush10.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush10);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush3);
#endif
        MediQueueFrame->setPalette(palette1);
        MediQueueFrame->setFrameShape(QFrame::Shape::StyledPanel);
        MediQueueFrame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(MediQueueFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 81, 41));
        SimulatorFrame = new QFrame(MainWindow);
        SimulatorFrame->setObjectName("SimulatorFrame");
        SimulatorFrame->setGeometry(QRect(50, 170, 301, 191));
        SimulatorFrame->setFrameShape(QFrame::Shape::StyledPanel);
        SimulatorFrame->setFrameShadow(QFrame::Shadow::Raised);
        add5m = new QPushButton(SimulatorFrame);
        add5m->setObjectName("add5m");
        add5m->setGeometry(QRect(10, 80, 131, 41));
        add15m = new QPushButton(SimulatorFrame);
        add15m->setObjectName("add15m");
        add15m->setGeometry(QRect(150, 80, 131, 41));
        add30m = new QPushButton(SimulatorFrame);
        add30m->setObjectName("add30m");
        add30m->setGeometry(QRect(10, 130, 131, 41));
        add1h = new QPushButton(SimulatorFrame);
        add1h->setObjectName("add1h");
        add1h->setGeometry(QRect(150, 130, 131, 41));
        TimeSimulator = new QLabel(SimulatorFrame);
        TimeSimulator->setObjectName("TimeSimulator");
        TimeSimulator->setGeometry(QRect(20, 20, 91, 21));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setStrikeOut(false);
        TimeSimulator->setFont(font1);
        label_2 = new QLabel(SimulatorFrame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 261, 16));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setStrikeOut(false);
        label_2->setFont(font2);
        PatientsFrame = new QFrame(MainWindow);
        PatientsFrame->setObjectName("PatientsFrame");
        PatientsFrame->setGeometry(QRect(390, 170, 821, 151));
        PatientsFrame->setFrameShape(QFrame::Shape::StyledPanel);
        PatientsFrame->setFrameShadow(QFrame::Shadow::Raised);
        StatsFrame = new QFrame(MainWindow);
        StatsFrame->setObjectName("StatsFrame");
        StatsFrame->setGeometry(QRect(50, 380, 301, 281));
        StatsFrame->setFrameShape(QFrame::Shape::StyledPanel);
        StatsFrame->setFrameShadow(QFrame::Shadow::Raised);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "MediQueue", nullptr));
        add5m->setText(QCoreApplication::translate("MainWindow", "+5m", nullptr));
        add15m->setText(QCoreApplication::translate("MainWindow", "+15m", nullptr));
        add30m->setText(QCoreApplication::translate("MainWindow", "+30m", nullptr));
        add1h->setText(QCoreApplication::translate("MainWindow", "+1h", nullptr));
        TimeSimulator->setText(QCoreApplication::translate("MainWindow", "Time Simulator", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Advance time to simulate patient waiting time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
