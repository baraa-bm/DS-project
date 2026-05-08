#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->NewPatient->hide();

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