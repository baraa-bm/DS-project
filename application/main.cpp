#include "../DataStructures/priorityQueue.h"
int main(){
    task task1;
    task task2;
    task task3;
    task task4;
    task task5;

    task1.id = 1;
    task2.id = 2;
    task3.id = 3;
    task4.id = 4; 
    task5.id = 5;

    priorityQueue PQ;

    PQ.insert(task1, 1);
    PQ.insert(task2, 2);
    PQ.insert(task3, 2);
    PQ.insert(task4, 3);
    PQ.insert(task5, 1);

    for(int i = 0; i < 5; i++){
        cout << PQ.top().id << endl;
        PQ.pop();
    }

    return 0;
}