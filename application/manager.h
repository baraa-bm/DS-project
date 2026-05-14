#ifndef MANAGER_H
#define MANAGER_H

#include "task.h"
#include "List.h"
#include "PriorityQueue.h"
#include "queue.h"
#include <iostream>
using namespace std;

class manager {
private:
    priorityQueue pq_tasks; // Pending queue (priority-ordered)
    queue<task*> holdTasks;        // Tasks on hold (FIFO)

    // Helper function to keep task status synchronized
    void updateTaskStatusInList(task *t, status status);

public:
    manager() : currentTask(nullptr), completedTasks(0) {}

    List<task> l_tasks;           // Main task list

    task* currentTask;
    int completedTasks;            // Counter for completed tasks

    // Add a new task to the system
    void addtask(task * newTask, int priority);

    // Mark task as executed and update metrics
    void executeTask(task *completedTask);

    // Get all tasks
    List<task> &getTasks();

    // Get tasks on hold
    queue<task*> &getHoldTasks();

    // Create a new task object
    task* createTask(Time arrival_time, Time execution_duration, string name, int priority);

    // Update task states based on elapsed time
    // This is called when global time advances
    void updateTasks(Time *globalTime);

    // Calculate total execution time for incomplete tasks
    float totalTimeExcecution();

    // Calculate average waiting time across all completed tasks
    float averageWaitingTime();

    // Calculate throughput (tasks completed per hour)
    float taskThroughput();

    // Print all tasks in the system
    void printAllTasks();

    // Print currently executing task
    void printCurrentTask();

    // Destructor - cleanup
    ~manager() {
        // Clean up the hold queue
        while (!holdTasks.isEmpty()) {
            task *t = holdTasks.dequeue();
            delete t;
        }
        // Clean up the priority queue
        while (!pq_tasks.isEmpty()) {
            task *t = pq_tasks.top();
            pq_tasks.pop();
            delete t;
        }
        // Clean up the main list
        int size = l_tasks.sizeOfList();
        for (int i = 0; i < size; i++) {
            // Note: if l_tasks stores values (not pointers), no delete needed
            // But if storing pointers: delete &l_tasks[i] (if heap-allocated)
        }
        if (currentTask != nullptr) {
            delete currentTask;
        }
    }

    // Make priority queue accessible for display
    friend class MainWindow;
};

#endif // MANAGER_H