#include "queue.h"
queue::queue(): capacity(8), head(0), tail(0), size(0) {
    data = new task[capacity];
}

queue::queue(int initial_capacity): capacity(initial_capacity), head(0), tail(0), size(0) {
    data = new task[capacity];
}

queue::~queue() {
    delete[] data;
}
//==========================================================
void queue::enqueue(const task& Task) {
    if (size == capacity)
        throw std::overflow_error("Error: capacity exceeded");

    data [tail] = Task;
    tail = (tail + 1) % capacity; //circular queue implementation part
    ++size;
}

task queue::dequeue() {
    if (isEmpty())
        throw std::underflow_error("Error: queue is empty");

    task t = data [head];
    head = (head + 1) % capacity;
    --size;
    return t;
}

const task& queue::front() const {
    if (isEmpty())
        throw std::underflow_error("Error: queue is empty");

    return data [head];
}

int queue::sizeOfQueue() const {
    return size;
}

bool queue::isEmpty() const {
    return (size == 0);
}


