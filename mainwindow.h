#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "manager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    manager *Task_Manager = nullptr;
    Time *currentTime = new Time(5, 0);
    int simulatedMinutes = 0;
    int realTimeSeconds = 0; //this is to update the remaining time of the current task accuratly accounting for the passing real time

    void displayTime(Time time);
    void displayPcTime();
    void updateTime(Time increment);

    void addSecond();

    void refreshPatientsList();

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddPatient_clicked();

    void on_CheckIn_clicked();

    void on_close_checkIn_clicked();

    void on_add5m_clicked();

    void on_add15m_clicked();

    void on_add30m_clicked();

    void on_add1h_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
