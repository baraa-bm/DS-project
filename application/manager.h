#ifndef ADS_PROJECT_MANAGER_H
#define ADS_PROJECT_MANAGER_H

#include "task.h"
#include "List.h"
#include "queue.h"
#include "priorityQueue.h"

class manager {
private:
    queue<task*> q_tasks;
    List<task> l_tasks;

public:
    int completedTasks = 0;
    task* currentTask;

    List<task>& getTasks();
    priorityQueue pq_tasks;

    task* createTask(Time arrival_time, Time execution_duration, string name, int priority);
    void addtask(task* newTask, int priority);
    void executeTask(task*);
    void updateTasks(Time * globalTime);
    void printAllTasks();

    void printCompletedTask();   // fix: was pringCompletedTask (typo)

    void printCurrentTask();

    float averageWaitingTime();
    float taskThroughput();
    float totalTimeExcecution();

    friend class PersistenceManager;
};
#endif //ADS_PROJECT_MANAGER_H
