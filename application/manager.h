#ifndef ADS_PROJECT_MANAGER_H
#define ADS_PROJECT_MANAGER_H

#include "../DataStructures/task.h"
#include "../DataStructures/List.h"
#include "../DataStructures/queue.h"
#include "../DataStructures/priorityQueue.h"

//the manager class handles the logic of the program using the data structures and the tasks.

class manager {
private:
    queue<task*> q_tasks;
    List<task> l_tasks;


    //current user
public:
    int completedTasks = 0;
    task* currentTask; //for printing the current patient with the doctor
    //moving pq_tasks to be public
    priorityQueue pq_tasks;

    //added for tasks display
    List<task>& getTasks();

    task* createTask(Time arrival_time, Time execution_duration, string name, int priority);
    void addtask(task * newTask, int priority);
    void executeTask(task *);
    void updateTasks(Time *globalTime);
    void printAllTasks();
    void printCompletedTask();
    //void printNextTask();
    void printCurrentTask();

    //stats
    float averageWaitingTime();
    float taskThroughput();
    float totalTimeExcecution();

    // Allow persistence to read/write tasks without changing data structures.
    friend class PersistenceManager;
};
#endif //ADS_PROJECT_MANAGER_H
