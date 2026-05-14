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
    ui->currentTaskInfo->setText("No patients in queue");

    // Show the real PC time when the window opens.
    displayPcTime();

    // Update the clock every second so the seconds visibly move.
    QTimer *clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, this, &MainWindow::displayPcTime);
    connect(clockTimer, &QTimer::timeout, this, &MainWindow::addSecond);
    clockTimer->start(1000);

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

void MainWindow::addSecond(){
    realTimeSeconds++;

    if(realTimeSeconds == 60){
        simulatedMinutes++;
        realTimeSeconds = 0;
    }
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
        ui->QueueStatus->show();
        ui->QueueStatus->setText("No Patients in Queue");
        ui->currentTaskInfo->setText("No patients in queue");
        ui->CurcialNumber->setText("0");
        ui->UrgentNumber->setText("0");
        ui->NormaNumber->setText("0");
        ui->TotaNumber->setText("0");
        return;
    }

    ui->QueueStatus->hide();

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
        QString executionTime = QString("%1:%2")
                                    .arg(t->excution_duration.hours, 2, 10, QChar('0'))
                                    .arg(t->excution_duration.minutes, 2, 10, QChar('0'));

        QString text = priorityLabel + "  |  " +
                       QString::fromStdString(t->name) +
                       " | Execution Duration: " + executionTime;

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

    if(Task_Manager->currentTask != nullptr){

        // --- FIX LOGIC START ---
        // If the task has changed (or just started), reset the starting marker
        if (Task_Manager->currentTask != lastTrackedTask) {
            simulatedMinutesAtTaskStart = simulatedMinutes;
            lastTrackedTask = Task_Manager->currentTask;
        }

        // Calculate minutes spent: Current total - marker at start
        int minutesSpent = simulatedMinutes - simulatedMinutesAtTaskStart;

        // Calculate remaining: Total duration - minutes spent
        // We use toTotalMinutes() to make math easier, then convert back to Time
        int totalDurationMins = Task_Manager->currentTask->excution_duration.toTotalMinutes();
        int remainingMins = totalDurationMins - minutesSpent;

        if (remainingMins < 0) remainingMins = 0;

        Time remaining(remainingMins / 60, remainingMins % 60);
        // --- FIX LOGIC END ---

        QString priorityLabel;
        // ... (Keep your existing color/label logic) ...

        QString executionTime = QString("%1:%2")
                                    .arg(Task_Manager->currentTask->excution_duration.hours, 2, 10, QChar('0'))
                                    .arg(Task_Manager->currentTask->excution_duration.minutes, 2, 10, QChar('0'));

        QString remainingTime = QString("%1:%2")
                                    .arg(remaining.hours, 2, 10, QChar('0'))
                                    .arg(remaining.minutes, 2, 10, QChar('0'));

        QString text = priorityLabel + "  |  " +
                       QString::fromStdString(Task_Manager->currentTask->name) +
                       " | Duration: " + executionTime +
                       " | Remaining: " + remainingTime;

        ui->currentTaskInfo->setText(text);
    } else {
        lastTrackedTask = nullptr; // Reset if queue is empty
        ui->currentTaskInfo->setText("No patients in queue");
    }

    //handling hold tasks
    if (!Task_Manager->getHoldTasks().isEmpty()) {

        queue<task*> &queue = Task_Manager->getHoldTasks();
        int size = queue.sizeOfQueue();

        for (int i = 0; i < size; i++) {

            task *t = queue.front();
            queue.dequeue();

            if (t != nullptr) {

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

                QString executionTime = QString("%1:%2")
                                            .arg(t->excution_duration.hours, 2, 10, QChar('0'))
                                            .arg(t->excution_duration.minutes, 2, 10, QChar('0'));

                QString text = "(ON HOLD) " + priorityLabel + " | " +
                               QString::fromStdString(t->name) +
                               " | Execution Duration: " + executionTime;

                QListWidgetItem *item = new QListWidgetItem(text);

                item->setForeground(QBrush(textColor));
                item->setBackground(QBrush(rowColor));
                item->setSizeHint(QSize(0, 38));

                ui->PatientsList->addItem(item);
            }

            // restore queue order
            queue.enqueue(t);
        }
    }
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

    // Add the minutes from the Time Simulator buttons.
    QTime shownTime = pcTime.addSecs(simulatedMinutes * 60);

    // Save hours and minutes in the old project Time object.
    currentTime->hours = shownTime.hour();
    currentTime->minutes = shownTime.minute();

    // Show hours, minutes, and seconds on the screen.
    ui->CurrentTime->setText(shownTime.toString("HH:mm:ss"));

    if (Task_Manager != nullptr) {
        Task_Manager->updateTasks(currentTime); // Tell manager time passed
        refreshPatientsList();                  // Redraw the UI
    }
}

void MainWindow::updateTime(Time increment)
{
    // Remember how much fake time the simulator added.
    simulatedMinutes += increment.toTotalMinutes();

    // Redraw the clock right away.
    displayPcTime();
}

void MainWindow::on_add5m_clicked()
{
    updateTime(Time{0, 5});
    Task_Manager->updateTasks(currentTime);
    refreshPatientsList();
}

void MainWindow::on_add15m_clicked()
{
    updateTime(Time{0, 15});
    Task_Manager->updateTasks(currentTime);
    refreshPatientsList();
}

void MainWindow::on_add30m_clicked()
{
    updateTime(Time{0, 30});
    Task_Manager->updateTasks(currentTime);
    refreshPatientsList();
}

void MainWindow::on_add1h_clicked()
{
    updateTime(Time{1, 0});
    Task_Manager->updateTasks(currentTime);
    refreshPatientsList();
}

