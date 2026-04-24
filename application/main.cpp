#include <iostream>
#include "manager.h"

Time globalTime(0, 0);
int x;
void advanceTime(int h, int m){
    globalTime.hours += h;
    globalTime.minutes += m;
}


int main(){

    manager mgr;
    bool isRunning = true;
    while(isRunning){
        //enter username and password

        //load data

        //options
        cout << "========== Options ============ \n";
        cout << "1- Add a task";
        cout << "2- Show all tasks";
        cout << "3- Show next task";
        cout << "4- Show current task";
        cout << "5- Average waiting time";
        cout << "6- Total excecution time";
        cout << "7- Tasks throughput";
        cout << "8- Advance time";
        cout << "0 - exit";

        int choice;
        cin >> choice;
        string name;
        int h,m,p;
        switch (choice)
        {
        case 1:
        cout << "Task Name: "; cin >> name;
        cout << "Hours, Minutes: "; cin >> h >> m;
        cout << "Priority: "; cin >> p;
        {
            task* newTask = new task();
            newTask->name = name;
            newTask->arrival_time = globalTime;
            newTask->excution_duration = Time(h, m);
            newTask->priority = p;

            mgr.addtask(newTask, p);
        }
            break;
        case 2:
            mgr.printAllTasks();
            break;
        case 3:
            mgr.printNextTask();
            break;
         case 4:
            mgr.printCurrentTask();
            break;
        default:
            break;
        }

    }

    return 0;
}
