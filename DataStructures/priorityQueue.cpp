// #include <iostream>
// #include <utility>
// #include <exception>
// #include "../Application/task.h"
// using namespace std;

// class priorityQueue{
//     //private data members
//     private:
        
//         //Element struct with value and priority
//         struct element{ //start of struct
//             task value;
//             int priority;
//             int order = 0;

//             //constructor
//             element() : value(), priority(0) {}

//             element(const task& value, int priority) : value(value), priority(priority) {}

//             //move constructor
//             element(element&& other) noexcept 
//             : value(move(other.value)), priority(other.priority) {} //noexcept tells the compiler that no excpetions will be no exceptions

//             //move assignment
//             element& operator=(element&& other_element){
//                 if(this == &other_element) return *this;

//                 this->value = move(other_element.value);
//                 this->priority = other_element.priority;

//                 return *this;
//             }

//             //copy assignment
//             element& operator=(const element& other){
//                 if(this == &other) return *this;
//                 this->value = other.value;      // copy value
//                 this->priority = other.priority;
//                 return *this;
//             }

//         }; //end of struct
        
//         //max heap representing the priority queue
//         element * maxHeap = nullptr;

//         int current_order = 0;

//         int p_size = 0; //current size occupied
//         int p_capacity = 0; //max_size
        
//     //private functions    
//     private:
//         void ReAlloc(int newCapacity){
//             // 1. allocate a new block of memory
//             // 2. copy/move old elements into new block
//             // 3. delete
//             element * newBlock = new element[newCapacity + 1]; // +1 because of 1-base indecies

//             //if we are reducing the size
//             if(p_size + 1 > newCapacity)
//                 p_size = newCapacity;

//             for(int i = 1; i <= p_size; i++)
//                 newBlock[i] = move(maxHeap[i]);

//             delete[] maxHeap;
//             maxHeap = newBlock;
//             p_capacity = newCapacity;
//         }

//         int p_parent(int i) {return i/2;}
//         int p_left(int i) {return i*2;}
//         int p_right(int i) {return (i*2 + 1);}

//         void swap(int i, int j){
//             element temp = move(maxHeap[i]);
//             maxHeap[i] = move(maxHeap[j]);
//             maxHeap[j] = move(temp);
//         }

//         void fix_heap(int index){
//             while(index > 1){
//                 int parent = p_parent(index);

//                 if(maxHeap[index].priority > maxHeap[parent].priority){
//                     swap(index, parent);
//                     index = parent;
//                 }
//                 else return;
//             }
//         }
 
//     //public functions
//     public:
//         priorityQueue(){
//             ReAlloc(2);
//         }

//         //copy constructor
//         priorityQueue(const priorityQueue& other){
//             //copy size and capacity
//             this->p_size = other.p_size;
//             this->p_capacity = other.p_capacity;

//             //allocate a new heap
//             this->maxHeap = new element[p_capacity + 1];

//             //copy each element
//             for(int i = 1; i <= p_size; i++){
//                 this->maxHeap[i] = other.maxHeap[i];
//             }
//         }

//         //move constructor
//         priorityQueue(priorityQueue&& other){
//             //copy size and capacity
//             this->p_size = other.p_size;
//             this->p_capacity = other.p_capacity;

//             //point to the other max heap
//             this->maxHeap = other.maxHeap;
            
//             //free the other max heap
//             other.maxHeap = nullptr;
//             other.p_size = 0;
//             other.p_capacity = 0;
//         }

//         void insert(const task& val, int priority){
//             //initialize element
//             element newElement(val, priority);

//             //update the order
//             newElement.order = current_order;
//             current_order ++;

//             //handle first insertion
//             if(p_size == 0){
//                 maxHeap[1] = move(newElement);
//                 p_size ++;
//                 return;
//             }

//             //if a resize is needed
//             if(p_size >= p_capacity){
//                 ReAlloc(p_capacity + p_capacity/2);
//             }

//             //index of the new element
//             int new_index = p_size + 1; 

//             //insert new element
//             maxHeap[new_index] = move(newElement);
//             p_size ++;

//             //modify max heap after inserting
//             fix_heap(new_index);
//         }
//         //returns the value of the top element (highest priority)
//         const task& top() const {
//             if (p_size == 0) {
//                 throw std::runtime_error("Priority queue is empty");
//             }
//             return maxHeap[1].value;
//         }

//         //removes the top (highest priority) element from the queue
//         void pop() {
//             //incase of empty queue
//             if (p_size == 0) {
//                 return; 
//             }

//             //replace the root element with the last element in the heap
//             maxHeap[1] = move(maxHeap[p_size]);
//             p_size--;

//             //modify max heap after removing (Sift Down)
//             int current = 1;
            
//             //continue while there is at least a left child
//             while (p_left(current) <= p_size) {
//                 int max_child = p_left(current);
                
//                 //if a right child exists and > left child, update max_child
//                 if (p_right(current) <= p_size && maxHeap[p_right(current)].priority > maxHeap[max_child].priority) {
//                     max_child = p_right(current);
//                 }

//                 //if the current element and >= largest child, we're done
//                 if (maxHeap[current].priority >= maxHeap[max_child].priority) {
//                     break;
//                 }

//                 //o.w, swap with the largest child and continue down the tree
//                 swap(current, max_child);
//                 current = max_child;
//             }
//         }

//         bool isEmpty() const {
//             return p_size == 0;
//         }
        
//         int size() const {return p_size;}
//         int capacity() const {return p_capacity;}

//         ~priorityQueue(){
//             delete[] maxHeap;
//         }
// };

#include "priorityQueue.h"

// ================= element =================

priorityQueue::element::element() 
    : value(), priority(0), order(0) {}

priorityQueue::element::element(const task& value, int priority)
    : value(value), priority(priority), order(0) {}

priorityQueue::element::element(element&& other) noexcept
    : value(move(other.value)), priority(other.priority), order(other.order) {}

priorityQueue::element& priorityQueue::element::operator=(element&& other) {
    if (this == &other) return *this;

    value = move(other.value);
    priority = other.priority;
    order = other.order;
    return *this;
}

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

// copy constructor
priorityQueue::priorityQueue(const priorityQueue& other) {
    p_size = other.p_size;
    p_capacity = other.p_capacity;
    current_order = other.current_order;

    maxHeap = new element[p_capacity + 1];

    // copy each element
    for (int i = 1; i <= p_size; i++) {
        maxHeap[i] = other.maxHeap[i];
    }
}

// move constructor
priorityQueue::priorityQueue(priorityQueue&& other) {
    p_size = other.p_size;
    p_capacity = other.p_capacity;
    current_order = other.current_order;

    maxHeap = other.maxHeap;

    other.maxHeap = nullptr;
    other.p_size = 0;
    other.p_capacity = 0;
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
        newBlock[i] = move(maxHeap[i]);

    delete[] maxHeap;
    maxHeap = newBlock;
    p_capacity = newCapacity;
}

int priorityQueue::p_parent(int i) { return i / 2; }
int priorityQueue::p_left(int i) { return i * 2; }
int priorityQueue::p_right(int i) { return i * 2 + 1; }

void priorityQueue::swap(int i, int j) {
    element temp = move(maxHeap[i]);
    maxHeap[i] = move(maxHeap[j]);
    maxHeap[j] = move(temp);
}

// sift-up (heapify up)
void priorityQueue::fix_heap(int index) {
    while (index > 1) {
        int parent = p_parent(index);

        // compare priority first, then insertion order (FIFO tie-break)
        if (maxHeap[index].priority > maxHeap[parent].priority ||
           (maxHeap[index].priority == maxHeap[parent].priority &&
            maxHeap[index].order < maxHeap[parent].order)) {

            swap(index, parent);
            index = parent;
        } else return;
    }
}

// ================= public functions =================

void priorityQueue::insert(const task& val, int priority) {
    // create new element
    element newElement(val, priority);

    // assign insertion order (for tie-breaking)
    newElement.order = current_order++;

    // first insertion
    if (p_size == 0) {
        maxHeap[1] = move(newElement);
        p_size++;
        return;
    }

    // resize if needed
    if (p_size >= p_capacity) {
        ReAlloc(p_capacity + p_capacity / 2);
    }

    // insert at end
    int new_index = p_size + 1;
    maxHeap[new_index] = move(newElement);
    p_size++;

    // restore heap property
    fix_heap(new_index);
}

const task& priorityQueue::top() const {
    if (p_size == 0)
        throw runtime_error("Priority queue is empty");

    return maxHeap[1].value;
}

// sift-down (heapify down)
void priorityQueue::pop() {
    if (p_size == 0) return;

    maxHeap[1] = move(maxHeap[p_size]);
    p_size--;

    int current = 1;

    while (p_left(current) <= p_size) {
        int max_child = p_left(current);

        if (p_right(current) <= p_size &&
           (maxHeap[p_right(current)].priority > maxHeap[max_child].priority ||
           (maxHeap[p_right(current)].priority == maxHeap[max_child].priority &&
            maxHeap[p_right(current)].order < maxHeap[max_child].order))) {

            max_child = p_right(current);
        }

        if (maxHeap[current].priority > maxHeap[max_child].priority ||
           (maxHeap[current].priority == maxHeap[max_child].priority &&
            maxHeap[current].order < maxHeap[max_child].order)) {
            break;
        }

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
