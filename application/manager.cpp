#include "manager.h"

void manager::addtask(task * newTask, int priority){
    l_tasks.push_back(*newTask);
    pq_tasks.insert(newTask, priority);
}

void manager::popTask(task *completedTask){
    pq_tasks.pop();
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
    
    float totalHours = hours + (minutes/60);
    return totalHours;
}

float manager::averageWaitingTime(){
    int completedTasks = 0;
    float waitingTime_h = 0;
    float waitingTime_m = 0;
    int size = l_tasks.sizeOfList();

    for(int i = 0; i < size; i++){
        if(l_tasks[i]._status == completed){
            completedTasks++;
            waitingTime_h += (l_tasks[i].start_time.hours - l_tasks[i].arrival_time.hours);
            waitingTime_m += (l_tasks[i].start_time.minutes - l_tasks[i].arrival_time.minutes);
        }
    }

    float AWT = (waitingTime_h + waitingTime_m/60)/completedTasks;
}

