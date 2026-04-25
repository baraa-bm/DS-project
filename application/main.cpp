#include <iostream>
#include "manager.h"
#include "persistence.h"

#include <string>

using namespace std;

Time globalTime(0, 0);
int x;
void advanceTime(int h, int m){
    globalTime.hours += h;
    globalTime.minutes += m;
}


int main(){

    manager* mgr = new manager();
    mgr->currentTask = nullptr;
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
        cout << "9- Save to file (.json or .txt)";
        cout << "10- Load from file (.json or .txt)";
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

            mgr->addtask(newTask, p);
        }
            break;
        case 2:
            mgr->printAllTasks();
            break;
        case 3:
            mgr->printNextTask();
            break;
         case 4:
            mgr->printCurrentTask();
            break;
        case 8:
            cout << "Advance by (hours minutes): ";
            cin >> h >> m;
            advanceTime(h, m);
            cout << "Time is now: " << globalTime.hours << "h " << globalTime.minutes << "m\n";
            break;
        case 9: {
            cout << "Enter save path (e.g. data.json or data.txt): ";
            string path;
            cin >> path;
            string err;
            if (PersistenceManager::saveToFile(path, *mgr, globalTime, &err)) {
                cout << "Saved successfully to " << path << "\n";
            } else {
                cout << "Save failed: " << err << "\n";
            }
            break;
        }
        case 10: {
            cout << "Enter load path (e.g. data.json or data.txt): ";
            string path;
            cin >> path;
            PersistedState st;
            st.globalTime = Time(0, 0);
            string err;
            manager* fresh = PersistenceManager::loadNewFromFile(path, st, &err);
            if (!fresh) {
                cout << "Load failed: " << err << "\n";
                break;
            }
            delete mgr;
            mgr = fresh;
            globalTime = st.globalTime;
            cout << "Loaded successfully from " << path << "\n";
            cout << "Time restored to: " << globalTime.hours << "h " << globalTime.minutes << "m\n";
            break;
        }
        case 0:
            isRunning = false;
            break;
        default:
            break;
        }

    }

    delete mgr;
    return 0;
}
