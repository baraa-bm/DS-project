#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QBrush>
#include <QIntValidator>
#include <QListWidgetItem>
#include <QSize>
#include <QTime>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->NewPatient->hide();

    // Show the real PC time when the window opens.
    displayPcTime();

    ui->CrucialButton->setCheckable(true);
    ui->UrgentButton->setCheckable(true);
    ui->NormalButton->setCheckable(true);

    // Age should only accept whole numbers.
    ui->PatientAge->setValidator(new QIntValidator(0, 130, this));
    // Duration should only accept whole numbers.
    ui->TaskDuration->setValidator(new QIntValidator(1, 300, this));

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
    task **ordered = Task_Manager->pq_tasks.getAll(count);

    // These numbers are shown in Queue Statistics.
    int crucialCount = 0;
    int urgentCount = 0;
    int normalCount = 0;

    if (count == 0 || ordered == nullptr) {
        ui->QueueStatus->setText("No Patients in Queue");
        ui->CurcialNumber->setText("0");
        ui->UrgentNumber->setText("0");
        ui->NormaNumber->setText("0");
        ui->TotaNumber->setText("0");
        return;
    }

    ui->QueueStatus->setText(QString::number(count) + " patient(s) in queue");

    for (int i = 0; i < count; i++) {
        task *t = ordered[i];
        if (t == nullptr)
            continue;

        QString priorityLabel;
        QColor textColor;
        QColor rowColor;

        if (t->priority == 3) {
            priorityLabel = "Crucial";
            textColor = QColor("#b42318");
            rowColor = QColor("#fff1f3");
            crucialCount++;
        } else if (t->priority == 2) {
            priorityLabel = "Urgent";
            textColor = QColor("#b45309");
            rowColor = QColor("#fff7ed");
            urgentCount++;
        } else {
            priorityLabel = "Normal";
            textColor = QColor("#067647");
            rowColor = QColor("#edfdf4");
            normalCount++;
        }

        // Make each appointment easy to read in the display area.
        QString text = priorityLabel + "  |  " + QString::fromStdString(t->name);
        QListWidgetItem *item = new QListWidgetItem(text);
        item->setForeground(QBrush(textColor));
        item->setBackground(QBrush(rowColor));
        item->setSizeHint(QSize(0, 38));
        ui->PatientsList->addItem(item);
    }

    // Put the new numbers on the screen.
    ui->CurcialNumber->setText(QString::number(crucialCount));
    ui->UrgentNumber->setText(QString::number(urgentCount));
    ui->NormaNumber->setText(QString::number(normalCount));
    ui->TotaNumber->setText(QString::number(count));

    delete[] ordered;
}

void MainWindow::on_AddPatient_clicked()
{
    ui->NewPatient->show();
}

void MainWindow::on_CheckIn_clicked()
{
    QString firstName = ui->PatientName->text().trimmed();
    QString lastName = ui->PatientLastName->text().trimmed();
    QString age = ui->PatientAge->text().trimmed();

    if (firstName.isEmpty() || lastName.isEmpty() || age.isEmpty())
        return;

    if (Task_Manager == nullptr)
        return;

    // Save the details in one simple appointment text.
    QString Qname = firstName + " " + lastName + "  |  Age: " + age;
    string name = Qname.toStdString();

    int priority;
    if      (ui->NormalButton->isChecked())  { priority = 1; }
    else if (ui->CrucialButton->isChecked()) { priority = 3; }
    else if (ui->UrgentButton->isChecked())  { priority = 2; }
    else return;

    int durationMinutes = 10; // default to 10 minutes if left blank
    if (!ui->TaskDuration->text().isEmpty()) {
        durationMinutes = ui->TaskDuration->text().toInt();
    }


    Task_Manager->addtask(
        Task_Manager->createTask(*currentTime, Time{0, durationMinutes}, name, priority),
        priority
        );
    ui->PatientName->clear();
    ui->PatientLastName->clear();
    ui->TaskDuration->clear();
    ui->PatientAge->clear();
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
        QString("%1:%2").arg(time.hours, 2, 10, QChar('0')).arg(time.minutes, 2, 10, QChar('0')));
}

void MainWindow::displayPcTime()
{
    // Get the current time from the computer.
    QTime pcTime = QTime::currentTime();

    // Save hours and minutes in the old project Time object.
    currentTime->hours = pcTime.hour();
    currentTime->minutes = pcTime.minute();

    // Show hours, minutes, and seconds on the screen.
    ui->CurrentTime->setText(pcTime.toString("HH:mm:ss"));

    if (Task_Manager != nullptr) {
        Task_Manager->updateTasks(currentTime); // Tell manager time passed
        refreshPatientsList();                  // Redraw the UI
    }
}

void MainWindow::updateTime(Time increment)
{
    // Remember how much fake time the simulator added.
    Time newTime = increment + *currentTime;

    *currentTime = newTime;

    // Redraw the clock right away.
    displayTime(*currentTime);
}

void MainWindow::on_add5m_clicked()
{
    updateTime(Time{0, 5});
    Task_Manager->updateTasks(currentTime);
}

void MainWindow::on_add15m_clicked()
{
    updateTime(Time{0, 15});
    Task_Manager->updateTasks(currentTime);
}

void MainWindow::on_add30m_clicked()
{
    updateTime(Time{0, 30});
    Task_Manager->updateTasks(currentTime);
}

void MainWindow::on_add1h_clicked()
{
    updateTime(Time{1, 0});
    Task_Manager->updateTasks(currentTime);
}
