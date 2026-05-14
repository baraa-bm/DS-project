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

    // helper used only by getAll(): sift-down on a temporary copy,
    //Edited for holding feature

    static void siftDown(element* heap, int size, int index) {
        while (index * 2 <= size) {
            int maxChild = index * 2;
            // if (index * 2 + 1 <= size &&
            //     heap[index * 2 + 1].priority > heap[maxChild].priority)
            //     maxChild = index * 2 + 1;
            if (index * 2 + 1 <= size) {
                element& r = heap[index * 2 + 1];
                element& l = heap[maxChild];
                // same tiebreak logic: priority → wasHeld → order
                bool rightWins = (r.priority != l.priority)
                                     ? r.priority > l.priority
                                     : (r.value->wasHeld != l.value->wasHeld)
                                           ? r.value->wasHeld
                                           : r.order < l.order;
                if (rightWins) maxChild = index * 2 + 1;
            }
            element& cur = heap[index];
            element& child = heap[maxChild];
            //this method is a bit lengthy and complicated
            bool childWins = (child.priority != cur.priority) ? child.priority > cur.priority
                             : (child.value->wasHeld != cur.value->wasHeld)
                                       ? child.value->wasHeld
                                       : child.order < cur.order;
            if (!childWins) break;
            element tmp = heap[index];
            heap[index] = heap[maxChild];
            heap[maxChild] = tmp;
            index = maxChild;
        }

        //     if (heap[index].priority >= heap[maxChild].priority) break;
        //     element tmp = heap[index];
        //     heap[index] = heap[maxChild];
        //     heap[maxChild] = tmp;
        //     index = maxChild;
        // }
    }

//helper function for holding issue
    // Returns true if element at i should be above element at j
    bool higher(int i, int j) const {
        if (maxHeap[i].priority != maxHeap[j].priority)
            return maxHeap[i].priority > maxHeap[j].priority;   // higher priority wins
        if (maxHeap[i].value->wasHeld != maxHeap[j].value->wasHeld)
            return maxHeap[i].value->wasHeld;                   // held task wins tie
        return maxHeap[i].order < maxHeap[j].order;             // earlier insertion wins fifo
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
