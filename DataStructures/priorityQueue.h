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

    // helper used only by getAll(): sift-down on a temporary copy
    static void siftDown(element* heap, int size, int index) {
        while (index * 2 <= size) {
            int maxChild = index * 2;
            if (index * 2 + 1 <= size &&
                heap[index * 2 + 1].priority > heap[maxChild].priority)
                maxChild = index * 2 + 1;
            if (heap[index].priority >= heap[maxChild].priority) break;
            element tmp = heap[index];
            heap[index] = heap[maxChild];
            heap[maxChild] = tmp;
            index = maxChild;
        }
    }

public:
    priorityQueue();
    void insert(task *, int priority);
    task* top() const;
    void pop();
    bool isEmpty() const;
    int size() const;
    int capacity() const;
    ~priorityQueue();

    // Returns tasks in priority order (highest first) without modifying the heap.
    // Caller owns the returned array; delete[] it when done.
    task** getAll(int& outSize) const {
        outSize = p_size;
        if (p_size == 0) return nullptr;

        // copy the heap array (1-based, indices 1..p_size)
        element* tmp = new element[p_size + 1];
        for (int i = 1; i <= p_size; i++)
            tmp[i] = maxHeap[i];

        task** result = new task*[p_size];
        int tmpSize = p_size;

        for (int i = 0; i < p_size; i++) {
            // root of tmp heap is the current max
            result[i] = tmp[1].value;
            // move last element to root and sift down
            tmp[1] = tmp[tmpSize];
            tmpSize--;
            if (tmpSize > 0) siftDown(tmp, tmpSize, 1);
        }

        delete[] tmp;
        return result;
    }
};
#endif

// #ifndef PRIORITYQUEUE_H
// #define PRIORITYQUEUE_H

// #include <iostream>
// #include <utility>
// #include <exception>
// #include "task.h"

// using namespace std;

// class priorityQueue {
// private:
//     struct element {
//         task* value;
//         int priority;
//         int order;

//         element();
//         element(task *value, int priority);

//         element& operator=(const element& other);
//     };

//     element* maxHeap;

//     int current_order;
//     int p_size;
//     int p_capacity;

//     void ReAlloc(int newCapacity);

//     int p_parent(int i);
//     int p_left(int i);
//     int p_right(int i);

//     void swap(int i, int j);
//     void fix_heap(int index);

// public:
//     priorityQueue();

//     void insert(task *, int priority);
//     task * top() const;
//     void pop();

//     bool isEmpty() const;
//     int size() const;
//     int capacity() const;

//     ~priorityQueue();
// };

// #endif
