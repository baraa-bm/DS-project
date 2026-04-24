#include "manager.h"

void manager::addtask(task * newTask, int priority){
    l_tasks.push_back(*newTask);
    pq_tasks.insert(newTask, priority);
}

void manager::popTask(task *completedTask){
    completedTasks++;
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
    
    float totalHours = hours + (minutes/60.0);
    return totalHours;
}

float manager::averageWaitingTime(){

}


float manager::taskThroughput(){
float totalTime = totalTimeExcecution();

    if(totalTime == 0){
        return 0; // avoid division by zero
    }

    return completedTasks / totalTime;
}

