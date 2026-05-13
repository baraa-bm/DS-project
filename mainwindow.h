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
    // fix: initialize to nullptr so it's never a dangling pointer;
    //      assign a real manager in main() or via a setter before use
    manager *Task_Manager = nullptr;

    Time *currentTime = new Time(5,0);

    void displayTime(Time time);
    void updateTime(Time increment);

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refreshPatientsList();

private slots:
    void on_AddPatient_clicked();
    void on_CheckIn_clicked();
    void on_close_checkIn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif