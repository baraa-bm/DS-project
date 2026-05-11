#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->NewPatient->hide();

    ui->CurrentTime->setText(currentTime.hours + ":" + currentTime.minutes);

    //priority buttons set to checkable
    ui->CrucialButton->setCheckable(true);
    ui->UrgentButton->setCheckable(true);
    ui->NormalButton->setCheckable(true);

    //Button Group for priority selection
    QButtonGroup *priorityGroup = new QButtonGroup(this);

    priorityGroup->addButton(ui->CrucialButton);
    priorityGroup->addButton(ui->UrgentButton);
    priorityGroup->addButton(ui->NormalButton);

    priorityGroup->setExclusive(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddPatient_clicked()
{
    ui->NewPatient->show();
}

void MainWindow::on_CheckIn_clicked()
{
    if(ui->PatientName->text().isEmpty()){
        //error message
        return;
    }

    QString Qname = ui->PatientName->text();
    string name = Qname.toStdString();
    int priority;
    if(ui->NormalButton->isChecked()) {priority = 1;}
    else if(ui->CrucialButton->isChecked()) {priority = 2;}
    else if(ui->UrgentButton->isChecked()) {priority = 3;}
    else {//error message
        return;
    }

    Task_Manager->addtask(Task_Manager->createTask(currentTime, Time{0,10}, name , priority), priority);
    ui->NewPatient->hide();

    //display tasks
}

void MainWindow::on_close_checkIn_clicked()
{
    ui->NewPatient->hide();
}

