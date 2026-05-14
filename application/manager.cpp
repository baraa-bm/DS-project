#include "manager.h"

void manager::addtask(task * newTask, int priority,Time* globalTime){
    l_tasks.push_back(*newTask);

    if (currentTask != nullptr && priority > currentTask->priority) {
        // --- PREEMPTION LOGIC ---
        // 1. Calculate how much time the current patient already spent with doctor

        //an issue with the following piece of code
        //int timeSpentMins = newTask->arrival_time.toTotalMinutes() - currentTask->start_time.toTotalMinutes();
        //resolved
        int timeSpentMins = globalTime->toTotalMinutes() - currentTask->start_time.toTotalMinutes();

        if (timeSpentMins > 0) {
            int remainingMins = currentTask->excution_duration.toTotalMinutes() - timeSpentMins;
            if (remainingMins < 1) remainingMins = 1; // Prevent 0 min instant finish
            currentTask->excution_duration = Time(0, remainingMins);
        }

        currentTask->_status = hold;
        currentTask->wasHeld = true; //added for hold feature

        newTask->_status = current;
        // Insert new task into queue. currentTask is already in the queue
        pq_tasks.insert(newTask, priority);
        currentTask = pq_tasks.top(); // The highest priority instantly becomes current
    }
    else if (currentTask == nullptr) {
        // System is empty
        newTask->_status = current;
        pq_tasks.insert(newTask, priority);
        currentTask = pq_tasks.top();
    }
    else {
        // Normal addition
        newTask->_status = pending;
        pq_tasks.insert(newTask, priority);
    }

    // Update the copy in l_tasks so stats calculations are perfectly accurate
    int size = l_tasks.sizeOfList();
    for(int i = 0; i < size; i++){
        if(l_tasks[i].ID == newTask->ID){
            l_tasks[i]._status = newTask->_status;
            break;
        }
    }
}

List<task> &manager::getTasks(){
    return l_tasks;
}

task* manager::createTask(Time arrival_time, Time execution_duration, string name, int priority){
    task * newTask = new task(arrival_time, execution_duration, name, priority);
    newTask->start_time = arrival_time; // <-- Initialize start time to when they arrive
    return newTask;
}

void manager::executeTask(task *completedTask){
    completedTasks++;
    //display completed task
    int size = l_tasks.sizeOfList();
    for(int i = 0; i < size; i++){
        if(l_tasks[i].ID == completedTask->ID){
            l_tasks[i]._status = completed;
            l_tasks[i].start_time = completedTask->start_time;
            break;
        }
    }
}

void manager::printCompletedTask(){   // fix: renamed from pringCompletedTask
    cout << "\n[Completed Task]\n";
    cout << "  ID       : " << currentTask->ID << "\n";
    cout << "  Name     : " << currentTask->name << "\n";
    cout << "  Priority : " << currentTask->priority << "\n";
    cout << "  Arrival  : " << currentTask->arrival_time.hours << "h "
         << currentTask->arrival_time.minutes << "m\n";
    cout << "  Duration : " << currentTask->excution_duration.hours << "h "
         << currentTask->excution_duration.minutes << "m\n\n";
}


void manager::updateTasks(Time *globalTime){
    if (currentTask == nullptr) return;

    while (currentTask != nullptr) {
        Time finishTime = currentTask->start_time + currentTask->excution_duration;

        if (*globalTime >= finishTime) {
            currentTask->_status = completed;
            executeTask(currentTask);
            pq_tasks.pop();

            if (!pq_tasks.isEmpty()) {
                task* nextTask = pq_tasks.top();

                if (nextTask->_status == hold) {
                    // Resume held task from where it was interrupted
                    nextTask->start_time = finishTime;
                } else {
                    // Fresh task: start at max(arrival, now)
                    if (nextTask->arrival_time > finishTime)
                        nextTask->start_time = nextTask->arrival_time;
                    else
                        nextTask->start_time = finishTime;
                }

                currentTask = nextTask;
                currentTask->_status = current;

                // Sync status and start_time back to l_tasks
                for (int i = 0; i < l_tasks.sizeOfList(); i++) {
                    if (l_tasks[i].ID == currentTask->ID) {
                        l_tasks[i]._status = current;
                        l_tasks[i].start_time = currentTask->start_time;
                        break;
                    }
                }
            } else {
                currentTask = nullptr; // Doctor is free
            }
        } else {
            break; // Current patient still being treated
        }
    }
}
float manager::totalTimeExcecution(){
    int hours = 0; int minutes = 0;
    int size = l_tasks.sizeOfList();

    for(int i = 0; i < size; i++){
        if(l_tasks[i]._status != completed){
            hours += l_tasks[i].excution_duration.hours;
            minutes += l_tasks[i].excution_duration.minutes;
        }
    }

    float totalHours = hours + (minutes/60.0);
    return totalHours;
}

float manager::averageWaitingTime(){
    if(completedTasks == 0) return 0;   // fix: avoid divide-by-zero

    float waitingTime_h = 0;
    float waitingTime_m = 0;
    int size = l_tasks.sizeOfList();

    for(int i = 0; i < size; i++){
        if(l_tasks[i]._status == completed){
            waitingTime_h += (l_tasks[i].start_time.hours - l_tasks[i].arrival_time.hours);
            waitingTime_m += (l_tasks[i].start_time.minutes - l_tasks[i].arrival_time.minutes);
        }
    }

    float AWT = (waitingTime_h + waitingTime_m/60.0f) / completedTasks;
    return AWT;
}

float manager::taskThroughput(){
    float totalTime = totalTimeExcecution();

    if(totalTime == 0){
        return 0;
    }

    return completedTasks / totalTime;
}

void manager::printAllTasks(){
    int size = l_tasks.sizeOfList();

    if (size == 0) {
        cout << "No tasks in the system.\n";
        return;
    }

    cout << "\n========== All Tasks (" << size << ") ==========\n";

    for (int i = 0; i < size; i++) {
        task t = l_tasks[i];

        string statusLabel;
        if      (t._status == pending)   statusLabel = "[ PENDING   ]";
        else if (t._status == current)   statusLabel = "[ RUNNING   ]";
        else                             statusLabel = "[ COMPLETED ]";

        cout << "  ID       : " << t.ID           << "\n";
        cout << "  Name     : " << t.name         << "\n";
        cout << "  Priority : " << t.priority     << "\n";
        cout << "  Status   : " << statusLabel    << "\n";
        cout << "  Arrival  : " << t.arrival_time.hours      << "h "
             << t.arrival_time.minutes    << "m\n";
        cout << "  Duration : " << t.excution_duration.hours   << "h "
             << t.excution_duration.minutes << "m\n";
        cout << "------------------------------\n";
    }
    cout << "====================================\n\n";
}

void manager::printCurrentTask(){
    if (currentTask == nullptr) {
        cout << "No current task is running.\n";
        return;
    }

    cout << "\n[Current Task]\n";
    cout << "  ID       : " << currentTask->ID << "\n";
    cout << "  Name     : " << currentTask->name << "\n";
    cout << "  Priority : " << currentTask->priority << "\n";
    cout << "  Arrival  : " << currentTask->arrival_time.hours << "h "
         << currentTask->arrival_time.minutes << "m\n";
    cout << "  Duration : " << currentTask->excution_duration.hours << "h "
         << currentTask->excution_duration.minutes << "m\n";
}
