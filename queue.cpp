#include "queue.h"

template <typename T>
queue<T>::queue(): capacity(8), head(0), tail(0), size(0) {
    data = new T[capacity];
}

template <typename T>
queue<T>::queue(int initial_capacity): capacity(initial_capacity), head(0), tail(0), size(0) {
    data = new T[capacity];
}

template <typename T>
queue<T>::~queue() {
    delete[] data;
}

//==========================================================
template <typename T>
void queue<T>::enqueue(const T& element) {
    if (size == capacity)
        throw std::overflow_error("Error: capacity exceeded");

    data [tail] = element;
    tail = (tail + 1) % capacity; //circular queue implementation part
    ++size;
}

template <typename T>
T queue<T>::dequeue() {
    if (isEmpty())
        throw std::underflow_error("Error: queue is empty");

    T t = data [head];
    head = (head + 1) % capacity;
    --size;
    return t;
}

template <typename T>
const T& queue<T>::front() const {
    if (isEmpty())
        throw std::underflow_error("Error: queue is empty");

    return data [head];
}

template <typename T>
int queue<T>::sizeOfQueue() const {
    return size;
}

template <typename T>
bool queue<T>::isEmpty() const {
    return (size == 0);
}