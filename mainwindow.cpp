#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->NewPatient->hide();

    ui->CurrentTime->setText(
        QString::number(currentTime->hours) + ":" +
        QString::number(currentTime->minutes).rightJustified(2, '0')
        );

    ui->CrucialButton->setCheckable(true);
    ui->UrgentButton->setCheckable(true);
    ui->NormalButton->setCheckable(true);

    QButtonGroup *priorityGroup = new QButtonGroup(this);
    priorityGroup->addButton(ui->CrucialButton);
    priorityGroup->addButton(ui->UrgentButton);
    priorityGroup->addButton(ui->NormalButton);
    priorityGroup->setExclusive(true);

    if (Task_Manager != nullptr)
        refreshPatientsList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshPatientsList()
{
    if (Task_Manager == nullptr || ui->PatientsList == nullptr)
        return;

    ui->PatientsList->clear();

    // get tasks in priority order from the heap (not insertion order from l_tasks)
    int count = 0;
    task** ordered = Task_Manager->pq_tasks.getAll(count);

    if (count == 0 || ordered == nullptr) {
        ui->QueueStatus->setText("No Patients in Queue");
        return;
    }

    ui->QueueStatus->setText(QString::number(count) + " patient(s) in queue");

    for (int i = 0; i < count; i++) {
        task* t = ordered[i];
        if (t == nullptr) continue;

        QString priorityLabel;
        if      (t->priority == 3) priorityLabel = "[Crucial]  ";
        else if (t->priority == 2) priorityLabel = "[Urgrnt] ";
        else                       priorityLabel = "[Normal]  ";

        QString text = priorityLabel + QString::fromStdString(t->name);
        ui->PatientsList->addItem(text);
    }

    delete[] ordered;
}

void MainWindow::on_AddPatient_clicked()
{
    ui->NewPatient->show();
}

void MainWindow::on_CheckIn_clicked()
{
    if (ui->PatientName->text().isEmpty())
        return;

    if (Task_Manager == nullptr)
        return;

    QString Qname = ui->PatientName->text();
    string name = Qname.toStdString();

    int priority;
    if      (ui->NormalButton->isChecked())  { priority = 1; }
    else if (ui->CrucialButton->isChecked()) { priority = 3; }
    else if (ui->UrgentButton->isChecked())  { priority = 2; }
    else return;

    Task_Manager->addtask(
        Task_Manager->createTask(*currentTime, Time{0, 10}, name, priority),
        priority
        );

    ui->PatientName->clear();
    ui->NewPatient->hide();
    refreshPatientsList();
}

void MainWindow::on_close_checkIn_clicked()
{
    ui->NewPatient->hide();
    refreshPatientsList();
}
// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include <QButtonGroup>

// MainWindow::MainWindow(QWidget *parent)
//     : QDialog(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);

//     ui->NewPatient->hide();

//     ui->CurrentTime->setText(currentTime.hours + ":" + currentTime.minutes);

//     //priority buttons set to checkable
//     ui->CrucialButton->setCheckable(true);
//     ui->UrgentButton->setCheckable(true);
//     ui->NormalButton->setCheckable(true);

//     refreshPatientsList();

//     //Button Group for priority selection
//     QButtonGroup *priorityGroup = new QButtonGroup(this);

//     priorityGroup->addButton(ui->CrucialButton);
//     priorityGroup->addButton(ui->UrgentButton);
//     priorityGroup->addButton(ui->NormalButton);

//     priorityGroup->setExclusive(true);
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
// }

// void MainWindow::refreshPatientsList()
// {
//     if(ui->PatientsList == nullptr)
//         return;

//     ui->PatientsList->clear();

//     List<task>& tasks = Task_Manager->getTasks();

//     int size = tasks.sizeOfList();

//     qDebug() << "Tasks size:" << size;

//     if(size <= 0)
//     {
//         ui->QueueStatus->setText("No Patients in Queue");
//         return;
//     }

//     for(int i = 0; i < size; i++)
//     {
//         task& t = tasks[i];

//         QString text =
//             QString::fromStdString(t.name);

//         ui->PatientsList->addItem(text);
//     }
// }

// void MainWindow::on_AddPatient_clicked()
// {
//     ui->NewPatient->show();
// }

// void MainWindow::on_CheckIn_clicked()
// {
//     if(ui->PatientName->text().isEmpty()){
//         //error message
//         return;
//     }

//     QString Qname = ui->PatientName->text();
//     string name = Qname.toStdString();
//     int priority;
//     if(ui->NormalButton->isChecked()) {priority = 1;}
//     else if(ui->CrucialButton->isChecked()) {priority = 2;}
//     else if(ui->UrgentButton->isChecked()) {priority = 3;}
//     else {//error message
//         return;
//     }

//     Task_Manager->addtask(Task_Manager->createTask(currentTime, Time{0,10}, name , priority), priority);
//     ui->NewPatient->hide();

//     //display tasks
// }

// void MainWindow::on_close_checkIn_clicked()
// {
//     ui->NewPatient->hide();
//     refreshPatientsList();
// }


