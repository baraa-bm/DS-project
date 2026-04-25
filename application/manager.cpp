#include "manager.h"

void manager::addtask(task * newTask, int priority){
    l_tasks.push_back(*newTask);
    if(pq_tasks.isEmpty()) currentTask = newTask;
    pq_tasks.insert(newTask, priority);
}

void manager::executeTask(task *completedTask){
    completedTasks++;
    pringCompletedTask();
    pq_tasks.pop();
}

void manager::pringCompletedTask(){
        cout << "\n[Completed Task]\n";
    cout << "  ID       : " << currentTask->ID << "\n";
    cout << "  Name     : " << currentTask->name << "\n";
    cout << "  Priority : " << currentTask->priority << "\n";
    cout << "  Arrival  : " << currentTask->arrival_time.hours << "h "
                         << currentTask->arrival_time.minutes << "m\n";
    cout << "  Duration : " << currentTask->excution_duration.hours << "h "
                         << currentTask->excution_duration.minutes << "m\n\n";
}

void manager::updateTasks(Time globalTime){
    if((currentTask->arrival_time + currentTask->excution_duration >= globalTime)){
        executeTask(pq_tasks.top());
        currentTask = pq_tasks.top();

        cout << "Current Task: \n";
        printCurrentTask();
    }
}

float manager::totalTimeExcecution(){
    int hours = 0; int minutes = 0;
    int size = l_tasks.sizeOfList();
    int tasksCount = 0;

    for(int i = 0; i < size; i++){
        if(l_tasks[i]._status != completed){
            hours += l_tasks[i].excution_duration.hours;
            minutes += l_tasks[i].excution_duration.minutes;
            tasksCount ++;
        }
    }
    
    float totalHours = hours + (minutes/60.0);
    return totalHours;
}

float manager::averageWaitingTime(){
    float waitingTime_h = 0;
    float waitingTime_m = 0;
    int size = l_tasks.sizeOfList();

    for(int i = 0; i < size; i++){
        if(l_tasks[i]._status == completed){
            waitingTime_h += (l_tasks[i].start_time.hours - l_tasks[i].arrival_time.hours);
            waitingTime_m += (l_tasks[i].start_time.minutes - l_tasks[i].arrival_time.minutes);
        }
    }

    float AWT = (waitingTime_h + waitingTime_m/60)/completedTasks;
    return AWT;
}


float manager::taskThroughput(){
float totalTime = totalTimeExcecution();

    if(totalTime == 0){
        return 0;
    }

    return completedTasks / totalTime;
}

// void manager::printNextTask(){
//     if (pq_tasks.isEmpty()) {
//         cout << "No tasks pending.\n";
//         return;
//     }
//     task* t = pq_tasks.top();
//     cout << "\n[Next Task]\n";
//     cout << "  ID       : " << t->ID       << "\n";
//     cout << "  Name     : " << t->name     << "\n";
//     cout << "  Priority : " << t->priority << "\n";
//     cout << "  Arrival  : " << t->arrival_time.hours << "h "
//                             << t->arrival_time.minutes << "m\n";
//     cout << "  Duration : " << t->excution_duration.hours << "h "
//                             << t->excution_duration.minutes << "m\n";
// }

void manager::printAllTasks(){
    int size = l_tasks.sizeOfList();

    if (size == 0) {
        cout << "No tasks in the system.\n";
        return;
    }

    cout << "\n========== All Tasks (" << size << ") ==========\n";

    for (int i = 0; i < size; i++) {
        task t = l_tasks[i];

        // Status label
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
