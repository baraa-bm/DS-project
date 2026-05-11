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
    manager *Task_Manager;
    Time currentTime = Time(5,0);

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddPatient_clicked();

    void on_CheckIn_clicked();

    void on_close_checkIn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
