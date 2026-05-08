/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
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
    QLabel *label_3;
    QLabel *label_4;
    QLabel *CurrentTime;
    QFrame *SimulatorFrame;
    QPushButton *add5m;
    QPushButton *add15m;
    QPushButton *add30m;
    QPushButton *add1h;
    QLabel *TimeSimulator;
    QLabel *label_2;
    QFrame *PatientsFrame;
    QLabel *QueueStatus;
    QFrame *StatsFrame;
    QLabel *label_5;
    QFrame *CrucialFrame;
    QLabel *label_6;
    QLabel *CurcialNumber;
    QFrame *UrgentFrame;
    QLabel *label_7;
    QLabel *UrgentNumber;
    QFrame *NormalFrame;
    QLabel *label_8;
    QLabel *NormaNumber;
    QFrame *TotalFrame;
    QLabel *label_9;
    QLabel *TotaNumber;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1250, 770);
        QPalette palette;
        QBrush brush(QColor(226, 239, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
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
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(47, 96, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        QBrush brush4(QColor(240, 247, 247, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        QBrush brush5(QColor(112, 120, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush5);
        QBrush brush6(QColor(150, 160, 160, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush7(QColor(225, 240, 240, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush9(QColor(0, 0, 0, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush10(QColor(112, 120, 120, 127));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush3);
        MediQueueFrame->setPalette(palette1);
        MediQueueFrame->setFrameShape(QFrame::Shape::WinPanel);
        MediQueueFrame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(MediQueueFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 261, 41));
        label_3 = new QLabel(MediQueueFrame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 70, 521, 24));
        label_4 = new QLabel(MediQueueFrame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1010, 30, 91, 16));
        CurrentTime = new QLabel(MediQueueFrame);
        CurrentTime->setObjectName("CurrentTime");
        CurrentTime->setGeometry(QRect(1030, 70, 48, 16));
        SimulatorFrame = new QFrame(MainWindow);
        SimulatorFrame->setObjectName("SimulatorFrame");
        SimulatorFrame->setGeometry(QRect(50, 170, 301, 191));
        SimulatorFrame->setFrameShape(QFrame::Shape::WinPanel);
        SimulatorFrame->setFrameShadow(QFrame::Shadow::Raised);
        add5m = new QPushButton(SimulatorFrame);
        add5m->setObjectName("add5m");
        add5m->setGeometry(QRect(20, 85, 76, 26));
        add15m = new QPushButton(SimulatorFrame);
        add15m->setObjectName("add15m");
        add15m->setGeometry(QRect(106, 85, 76, 26));
        add30m = new QPushButton(SimulatorFrame);
        add30m->setObjectName("add30m");
        add30m->setGeometry(QRect(20, 121, 76, 26));
        add1h = new QPushButton(SimulatorFrame);
        add1h->setObjectName("add1h");
        add1h->setGeometry(QRect(106, 121, 76, 26));
        TimeSimulator = new QLabel(SimulatorFrame);
        TimeSimulator->setObjectName("TimeSimulator");
        TimeSimulator->setGeometry(QRect(20, 20, 181, 21));
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
        PatientsFrame->setFrameShape(QFrame::Shape::WinPanel);
        PatientsFrame->setFrameShadow(QFrame::Shadow::Raised);
        QueueStatus = new QLabel(PatientsFrame);
        QueueStatus->setObjectName("QueueStatus");
        QueueStatus->setGeometry(QRect(300, 70, 261, 16));
        StatsFrame = new QFrame(MainWindow);
        StatsFrame->setObjectName("StatsFrame");
        StatsFrame->setGeometry(QRect(50, 380, 301, 261));
        StatsFrame->setFrameShape(QFrame::Shape::WinPanel);
        StatsFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_5 = new QLabel(StatsFrame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 10, 121, 16));
        CrucialFrame = new QFrame(StatsFrame);
        CrucialFrame->setObjectName("CrucialFrame");
        CrucialFrame->setGeometry(QRect(20, 50, 261, 31));
        CrucialFrame->setFrameShape(QFrame::Shape::StyledPanel);
        CrucialFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_6 = new QLabel(CrucialFrame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 0, 51, 31));
        CurcialNumber = new QLabel(CrucialFrame);
        CurcialNumber->setObjectName("CurcialNumber");
        CurcialNumber->setGeometry(QRect(240, 10, 48, 16));
        UrgentFrame = new QFrame(StatsFrame);
        UrgentFrame->setObjectName("UrgentFrame");
        UrgentFrame->setGeometry(QRect(20, 100, 261, 31));
        UrgentFrame->setFrameShape(QFrame::Shape::StyledPanel);
        UrgentFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_7 = new QLabel(UrgentFrame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 5, 48, 21));
        UrgentNumber = new QLabel(UrgentFrame);
        UrgentNumber->setObjectName("UrgentNumber");
        UrgentNumber->setGeometry(QRect(240, 10, 48, 16));
        NormalFrame = new QFrame(StatsFrame);
        NormalFrame->setObjectName("NormalFrame");
        NormalFrame->setGeometry(QRect(20, 150, 261, 31));
        NormalFrame->setFrameShape(QFrame::Shape::StyledPanel);
        NormalFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_8 = new QLabel(NormalFrame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 5, 48, 21));
        NormaNumber = new QLabel(NormalFrame);
        NormaNumber->setObjectName("NormaNumber");
        NormaNumber->setGeometry(QRect(240, 10, 48, 16));
        TotalFrame = new QFrame(StatsFrame);
        TotalFrame->setObjectName("TotalFrame");
        TotalFrame->setGeometry(QRect(20, 200, 261, 31));
        TotalFrame->setFrameShape(QFrame::Shape::StyledPanel);
        TotalFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_9 = new QLabel(TotalFrame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 0, 81, 31));
        TotaNumber = new QLabel(TotalFrame);
        TotaNumber->setObjectName("TotaNumber");
        TotaNumber->setGeometry(QRect(240, 10, 48, 16));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "MediQueue", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Advanced Patient Scheduling System", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Current Time", nullptr));
        CurrentTime->setText(QCoreApplication::translate("MainWindow", "0:00", nullptr));
        add5m->setText(QCoreApplication::translate("MainWindow", "+5m", nullptr));
        add15m->setText(QCoreApplication::translate("MainWindow", "+15m", nullptr));
        add30m->setText(QCoreApplication::translate("MainWindow", "+30m", nullptr));
        add1h->setText(QCoreApplication::translate("MainWindow", "+1h", nullptr));
        TimeSimulator->setText(QCoreApplication::translate("MainWindow", "Time Simulator", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Advance time to simulate patient waiting time", nullptr));
        QueueStatus->setText(QCoreApplication::translate("MainWindow", "No Patients in Queue", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Queue Statistics", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Crucial", nullptr));
        CurcialNumber->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Urgent", nullptr));
        UrgentNumber->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        NormaNumber->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Total Patients", nullptr));
        TotaNumber->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
