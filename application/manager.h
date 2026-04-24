#ifndef ADS_PROJECT_MANAGER_H
#define ADS_PROJECT_MANAGER_H

#include "task.h"
#include "List.h"
#include "queue.h"
#include "priorityQueue.h"

//the manager class handles the logic of the program using the data structures and the tasks.

class manager {
private:
    queue<task*> q_tasks;
    List<task> l_tasks;
    priorityQueue pq_tasks;

    //current user
public:
    void addtask(task * newTask, int priority);
    void popTask(task *);
    void printCurrentTasks();
    void printNextTask();

    //stats
    float averageWaitingTime();
    float taskThroughput();
    float totalTimeExcecution();
};


#endif //ADS_PROJECT_MANAGER_H