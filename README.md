# DS-project

## Description
This project is a simple task management system implemented using different data structures.
It shows how lists, queues, and priority queues can be used together to manage tasks efficiently.

## Project Structure
- main.cpp → main program
- List.cpp / List.h → dynamic array implementation
- queue.cpp / queue.h → queue implementation
- priorityQueue.cpp / priorityQueue.h → heap implementation

## Data Structures Used
- Dynamic Array (List)
- Queue (Circular Array)
- Priority Queue (Max Heap)

## Features
- Add tasks
- Process tasks
- Handle priority tasks
- Display tasks

## Time Complexity

### Insertion
- List (push_back): O(1) amortized
- Queue (enqueue): O(1)
- Priority Queue (insert): O(log n)

### Deletion
- Queue (dequeue): O(1)
- Priority Queue (pop): O(log n)

### Access
- List (indexing): O(1)
- Queue (front): O(1)
- Priority Queue (top): O(1)

### Resizing
- Dynamic array resize: O(n)
- Heap reallocation: O(n)

## Notes
- List resizing makes insertion amortized O(1)
- Priority queue uses heap → O(log n)
- Queue operations are constant time

## How to Run
Compile:
g++ main.cpp -o program

Run:
./program

## Author
CSCE 2211 Student Project
