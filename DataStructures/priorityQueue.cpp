#include "priorityQueue.h"

// ================= element =================

priorityQueue::element::element() 
    : value(), priority(0), order(0) {}

priorityQueue::element::element(task* value, int priority)
    : value(value), priority(priority), order(0) {}

priorityQueue::element& priorityQueue::element::operator=(const element& other) {
    if (this == &other) return *this;

    value = other.value;
    priority = other.priority;
    order = other.order;
    return *this;
}

// ================= priority queue =================

priorityQueue::priorityQueue() {
    maxHeap = nullptr;
    current_order = 0;
    p_size = 0;
    p_capacity = 0;
    ReAlloc(2);
}

// ================= private helpers =================

void priorityQueue::ReAlloc(int newCapacity) {
    // 1. allocate a new block of memory
    // 2. move old elements into new block
    // 3. delete old block

    element* newBlock = new element[newCapacity + 1]; // +1 because heap is 1-based

    // if shrinking capacity, adjust size
    if (p_size + 1 > newCapacity)
        p_size = newCapacity;

    for (int i = 1; i <= p_size; i++)
        newBlock[i] = maxHeap[i];

    delete[] maxHeap;
    maxHeap = newBlock;
    p_capacity = newCapacity;
}

int priorityQueue::p_parent(int i) { return i / 2; }
int priorityQueue::p_left(int i) { return i * 2; }
int priorityQueue::p_right(int i) { return i * 2 + 1; }

void priorityQueue::swap(int i, int j) {
    element temp = maxHeap[i];
    maxHeap[i] = maxHeap[j];
    maxHeap[j] = temp;
}

// shift-up (heapify up)
void priorityQueue::fix_heap(int index) {
    while (index > 1) {
        int parent = p_parent(index);

        //updated using the helper function we write in th .h
        if (higher(index, parent)) {   // ← was: maxHeap[index].priority > maxHeap[parent].priority
            swap(index, parent);
            index = parent;
        } else return;

        // // compare priority
        // if (maxHeap[index].priority > maxHeap[parent].priority) {
        //     swap(index, parent);
        //     index = parent;
        // } else return;
    }
}

// ================= public functions =================

void priorityQueue::insert(task * val, int priority) {
    // create new element
    element newElement(val, priority);

    // assign insertion order (for tie-breaking)
    newElement.order = current_order++;

    // first insertion
    if (p_size == 0) {
        maxHeap[1] = newElement;
        p_size++;
        return;
    }

    // resize if needed
    if (p_size >= p_capacity) {
        ReAlloc(p_capacity + p_capacity / 2);
    }

    // insert at end
    int new_index = p_size + 1;
    maxHeap[new_index] = newElement;
    p_size++;

    // restore heap property
    fix_heap(new_index);
}

task* priorityQueue::top() const {
    if (p_size == 0)
        return nullptr;

    return maxHeap[1].value;
}

// sift-down (heapify down)
void priorityQueue::pop() {
    if (p_size == 0) return;

    maxHeap[1] = maxHeap[p_size];
    p_size--;

    int current = 1;

    // while (p_left(current) <= p_size) {
    //     int max_child = p_left(current);

    //     if (p_right(current) <= p_size && (maxHeap[p_right(current)].priority > maxHeap[max_child].priority)) {

    //using the helper function for handling the hold
    while (p_left(current) <= p_size) {
        int max_child = p_left(current);
        if (p_right(current) <= p_size && higher(p_right(current), max_child)) {
            max_child = p_right(current);
        }

        // if (maxHeap[current].priority > maxHeap[max_child].priority) {
        //     break;
        // }
        //using the helper function as well
        if (!higher(max_child, current))
            break;

        swap(current, max_child);
        current = max_child;
    }
}

bool priorityQueue::isEmpty() const { return p_size == 0; }

int priorityQueue::size() const { return p_size; }

int priorityQueue::capacity() const { return p_capacity; }

priorityQueue::~priorityQueue() {
    delete[] maxHeap;
}
