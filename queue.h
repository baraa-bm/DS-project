#ifndef ADS_PROJECT_QUEUE_H
#define ADS_PROJECT_QUEUE_H
#include <stdexcept>

template <typename T>
class queue {
private:
    T* data;
    int capacity;
    int head;
    int tail;
    int size;

public:
    queue();
    queue(int);
    ~queue();

    void enqueue(const T&);
    T dequeue();
    const T& front() const;

    int sizeOfQueue() const;
    bool isEmpty() const;
};

#include "queue.cpp" // include template implementation
#endif //ADS_PROJECT_QUEUE_H