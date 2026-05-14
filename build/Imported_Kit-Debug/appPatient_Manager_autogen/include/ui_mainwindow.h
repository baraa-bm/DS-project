/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QListWidget *PatientsList;
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
    QPushButton *AddPatient;
    QFrame *NewPatient;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *PatientName;
    QLabel *label_13;
    QLineEdit *PatientLastName;
    QLabel *label_14;
    QLineEdit *PatientAge;
    QLabel *label_12;
    QPushButton *CheckIn;
    QPushButton *CrucialButton;
    QPushButton *UrgentButton;
    QPushButton *NormalButton;
    QPushButton *close_checkIn;
    QLineEdit *TaskDuration;
    QLabel *label_15;
    QFrame *currentTask;
    QLabel *label_16;
    QLabel *currentTaskInfo;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(982, 779);
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
        MediQueueFrame->setGeometry(QRect(38, 23, 888, 93));
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
        MediQueueFrame->setFrameShape(QFrame::Shape::WinPanel);
        MediQueueFrame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(MediQueueFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(8, 8, 200, 31));
        label_3 = new QLabel(MediQueueFrame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(8, 54, 399, 19));
        label_4 = new QLabel(MediQueueFrame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(760, 32, 90, 18));
        CurrentTime = new QLabel(MediQueueFrame);
        CurrentTime->setObjectName("CurrentTime");
        CurrentTime->setGeometry(QRect(760, 54, 90, 22));
        SimulatorFrame = new QFrame(MainWindow);
        SimulatorFrame->setObjectName("SimulatorFrame");
        SimulatorFrame->setGeometry(QRect(38, 130, 230, 146));
        SimulatorFrame->setFrameShape(QFrame::Shape::WinPanel);
        SimulatorFrame->setFrameShadow(QFrame::Shadow::Raised);
        add5m = new QPushButton(SimulatorFrame);
        add5m->setObjectName("add5m");
        add5m->setGeometry(QRect(23, 61, 77, 24));
        add15m = new QPushButton(SimulatorFrame);
        add15m->setObjectName("add15m");
        add15m->setGeometry(QRect(115, 61, 77, 24));
        add30m = new QPushButton(SimulatorFrame);
        add30m->setObjectName("add30m");
        add30m->setGeometry(QRect(23, 99, 77, 24));
        add1h = new QPushButton(SimulatorFrame);
        add1h->setObjectName("add1h");
        add1h->setGeometry(QRect(115, 99, 77, 24));
        TimeSimulator = new QLabel(SimulatorFrame);
        TimeSimulator->setObjectName("TimeSimulator");
        TimeSimulator->setGeometry(QRect(15, 15, 139, 16));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setStrikeOut(false);
        TimeSimulator->setFont(font1);
        label_2 = new QLabel(SimulatorFrame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(15, 38, 200, 12));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setStrikeOut(false);
        label_2->setFont(font2);
        PatientsFrame = new QFrame(MainWindow);
        PatientsFrame->setObjectName("PatientsFrame");
        PatientsFrame->setGeometry(QRect(290, 230, 631, 221));
        PatientsFrame->setMinimumSize(QSize(0, 116));
        PatientsFrame->setFrameShape(QFrame::Shape::WinPanel);
        PatientsFrame->setFrameShadow(QFrame::Shadow::Raised);
        PatientsList = new QListWidget(PatientsFrame);
        PatientsList->setObjectName("PatientsList");
        PatientsList->setGeometry(QRect(20, 10, 590, 201));
        PatientsList->setFrameShape(QFrame::Shape::WinPanel);
        PatientsList->setFrameShadow(QFrame::Shadow::Raised);
        PatientsList->setSortingEnabled(false);
        QueueStatus = new QLabel(PatientsFrame);
        QueueStatus->setObjectName("QueueStatus");
        QueueStatus->setGeometry(QRect(230, 100, 200, 16));
        StatsFrame = new QFrame(MainWindow);
        StatsFrame->setObjectName("StatsFrame");
        StatsFrame->setGeometry(QRect(40, 360, 230, 371));
        StatsFrame->setFrameShape(QFrame::Shape::WinPanel);
        StatsFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_5 = new QLabel(StatsFrame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 10, 180, 20));
        CrucialFrame = new QFrame(StatsFrame);
        CrucialFrame->setObjectName("CrucialFrame");
        CrucialFrame->setGeometry(QRect(15, 38, 200, 24));
        CrucialFrame->setFrameShape(QFrame::Shape::StyledPanel);
        CrucialFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_6 = new QLabel(CrucialFrame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(8, 0, 51, 24));
        CurcialNumber = new QLabel(CrucialFrame);
        CurcialNumber->setObjectName("CurcialNumber");
        CurcialNumber->setGeometry(QRect(184, 8, 37, 12));
        UrgentFrame = new QFrame(StatsFrame);
        UrgentFrame->setObjectName("UrgentFrame");
        UrgentFrame->setGeometry(QRect(15, 76, 200, 24));
        UrgentFrame->setFrameShape(QFrame::Shape::StyledPanel);
        UrgentFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_7 = new QLabel(UrgentFrame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(8, 3, 51, 16));
        UrgentNumber = new QLabel(UrgentFrame);
        UrgentNumber->setObjectName("UrgentNumber");
        UrgentNumber->setGeometry(QRect(184, 8, 37, 12));
        NormalFrame = new QFrame(StatsFrame);
        NormalFrame->setObjectName("NormalFrame");
        NormalFrame->setGeometry(QRect(15, 115, 200, 24));
        NormalFrame->setFrameShape(QFrame::Shape::StyledPanel);
        NormalFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_8 = new QLabel(NormalFrame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(8, 3, 61, 16));
        NormaNumber = new QLabel(NormalFrame);
        NormaNumber->setObjectName("NormaNumber");
        NormaNumber->setGeometry(QRect(184, 8, 37, 12));
        TotalFrame = new QFrame(StatsFrame);
        TotalFrame->setObjectName("TotalFrame");
        TotalFrame->setGeometry(QRect(15, 153, 200, 24));
        TotalFrame->setFrameShape(QFrame::Shape::StyledPanel);
        TotalFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_9 = new QLabel(TotalFrame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(8, 0, 111, 24));
        TotaNumber = new QLabel(TotalFrame);
        TotaNumber->setObjectName("TotaNumber");
        TotaNumber->setGeometry(QRect(184, 8, 37, 12));
        AddPatient = new QPushButton(MainWindow);
        AddPatient->setObjectName("AddPatient");
        AddPatient->setGeometry(QRect(40, 310, 230, 31));
        NewPatient = new QFrame(MainWindow);
        NewPatient->setObjectName("NewPatient");
        NewPatient->setGeometry(QRect(300, 470, 601, 261));
        NewPatient->setFrameShape(QFrame::Shape::WinPanel);
        NewPatient->setFrameShadow(QFrame::Shadow::Raised);
        label_10 = new QLabel(NewPatient);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(15, 15, 77, 12));
        label_11 = new QLabel(NewPatient);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(15, 46, 77, 12));
        PatientName = new QLineEdit(NewPatient);
        PatientName->setObjectName("PatientName");
        PatientName->setGeometry(QRect(15, 61, 175, 31));
        label_13 = new QLabel(NewPatient);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(205, 46, 77, 12));
        PatientLastName = new QLineEdit(NewPatient);
        PatientLastName->setObjectName("PatientLastName");
        PatientLastName->setGeometry(QRect(205, 61, 175, 31));
        label_14 = new QLabel(NewPatient);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(395, 46, 77, 12));
        PatientAge = new QLineEdit(NewPatient);
        PatientAge->setObjectName("PatientAge");
        PatientAge->setGeometry(QRect(395, 61, 180, 31));
        label_12 = new QLabel(NewPatient);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(15, 99, 54, 16));
        CheckIn = new QPushButton(NewPatient);
        CheckIn->setObjectName("CheckIn");
        CheckIn->setGeometry(QRect(280, 210, 291, 31));
        CrucialButton = new QPushButton(NewPatient);
        CrucialButton->setObjectName("CrucialButton");
        CrucialButton->setGeometry(QRect(15, 122, 170, 47));
        UrgentButton = new QPushButton(NewPatient);
        UrgentButton->setObjectName("UrgentButton");
        UrgentButton->setGeometry(QRect(205, 122, 170, 47));
        NormalButton = new QPushButton(NewPatient);
        NormalButton->setObjectName("NormalButton");
        NormalButton->setGeometry(QRect(395, 122, 180, 47));
        close_checkIn = new QPushButton(NewPatient);
        close_checkIn->setObjectName("close_checkIn");
        close_checkIn->setGeometry(QRect(552, 10, 24, 24));
        TaskDuration = new QLineEdit(NewPatient);
        TaskDuration->setObjectName("TaskDuration");
        TaskDuration->setGeometry(QRect(20, 210, 180, 31));
        label_15 = new QLabel(NewPatient);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 190, 91, 16));
        currentTask = new QFrame(MainWindow);
        currentTask->setObjectName("currentTask");
        currentTask->setGeometry(QRect(290, 130, 631, 80));
        currentTask->setFrameShape(QFrame::Shape::WinPanel);
        currentTask->setFrameShadow(QFrame::Shadow::Raised);
        label_16 = new QLabel(currentTask);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 30, 81, 16));
        currentTaskInfo = new QLabel(currentTask);
        currentTaskInfo->setObjectName("currentTaskInfo");
        currentTaskInfo->setGeometry(QRect(110, 30, 511, 20));

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
        AddPatient->setText(QCoreApplication::translate("MainWindow", "+ New Patient Check-In", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Patient Check-In", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        PatientName->setText(QString());
        PatientName->setPlaceholderText(QCoreApplication::translate("MainWindow", "First name", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        PatientLastName->setText(QString());
        PatientLastName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Last name", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        PatientAge->setText(QString());
        PatientAge->setPlaceholderText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        CheckIn->setText(QCoreApplication::translate("MainWindow", "Check-In Patient", nullptr));
        CrucialButton->setText(QCoreApplication::translate("MainWindow", "Crucial", nullptr));
        UrgentButton->setText(QCoreApplication::translate("MainWindow", "Urgent", nullptr));
        NormalButton->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        close_checkIn->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        TaskDuration->setText(QString());
        TaskDuration->setPlaceholderText(QCoreApplication::translate("MainWindow", "Minutes", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Task Duration", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Current Task:", nullptr));
        currentTaskInfo->setText(QCoreApplication::translate("MainWindow", "Placeholder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
