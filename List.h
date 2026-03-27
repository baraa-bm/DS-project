#ifndef ADS_PROJECT_LIST_H
#define ADS_PROJECT_LIST_H
#include "task.h"
#include <stdexcept>
//it is an implementation for the vector like operations
class List {
private:
    task* data;
    int capacity;
    int size;

    void resize(int);
    void checkBounds(int) const;

public:
    List();
    List(int);
    ~List();

    void push_back(const task &Task);
    const task& getter (int) const;
    task& operator[](int); //operator overloading as we get the task using index based.
    int sizeOfList() const;
    bool isEmpty() const;
};


#endif //ADS_PROJECT_LIST_H