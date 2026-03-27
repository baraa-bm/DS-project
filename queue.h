//
// Created by Youstina Abouelkher on 3/27/2026.
//

#ifndef ADS_PROJECT_QUEUE_H
#define ADS_PROJECT_QUEUE_H
#include "task.h"
#include <stdexcept>

class queue {
private:
    task* data;
    int capacity;
    int head;
    int tail;
    int size;

public:
    queue();
    queue(int);
    ~queue();

    void enqueue(const task&);
    task dequeue();
    const task& front() const;

    int sizeOfQueue() const;
    bool isEmpty() const;
};


#endif //ADS_PROJECT_QUEUE_H