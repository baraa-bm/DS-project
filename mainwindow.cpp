#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->NewPatient->hide();

    displayTime(*currentTime);

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

void MainWindow::displayTime(Time time)
{
    ui->CurrentTime->setText(
        QString("%1:%2")
            .arg(time.hours, 2, 10, QChar('0'))
            .arg(time.minutes, 2, 10, QChar('0'))
        );
}

void MainWindow::updateTime(Time increment)
{
    Time newTime = *currentTime + increment;
    *currentTime = newTime;

    displayTime(*currentTime);
}


void MainWindow::on_add5m_clicked()
{
    updateTime(Time{0, 5});
}


void MainWindow::on_add15m_clicked()
{
    updateTime(Time{0, 15});
}


void MainWindow::on_add30m_clicked()
{
    updateTime(Time{0, 30});
}


void MainWindow::on_add1h_clicked()
{
    updateTime(Time{1, 0});
}



