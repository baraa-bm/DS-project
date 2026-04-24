#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <utility>
#include <exception>
#include "task.h"

using namespace std;

class priorityQueue {
private:
    struct element {
        task* value;
        int priority;
        int order;

        element();
        element(task *value, int priority);

        element& operator=(const element& other);
    };

    element* maxHeap;

    int current_order;
    int p_size;
    int p_capacity;

    void ReAlloc(int newCapacity);

    int p_parent(int i);
    int p_left(int i);
    int p_right(int i);

    void swap(int i, int j);
    void fix_heap(int index);

public:
    priorityQueue();

    void insert(task *, int priority);
    task * top() const;
    void pop();

    bool isEmpty() const;
    int size() const;
    int capacity() const;

    ~priorityQueue();
};

#endif