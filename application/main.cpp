#include "../DataStructures/priorityQueue.h"

Time globalTime(0, 0);
int x;
void advanceTime(int h, int m){
    globalTime.hours += h;
    globalTime.minutes += m;
}


int main(){

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

        switch (choice)
        {
        case 1:
            break;
        
        default:
            break;
        }

    }

    return 0;
}