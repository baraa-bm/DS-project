#include "List.h"

List::List(): capacity(8), size(0) {
    data = new task[capacity];
}

List::List(int initial_capacity): capacity(initial_capacity), size(0) {
    data = new task[capacity];
}

List::~List() {
    delete[] data;
}

void List::push_back(const task& Task) {
    if (size == capacity)
        resize(capacity*2);
    data[size++] = Task; //appending the task to teh list.
}
//=============================================================
const task& List::getter (int index) const {
    checkBounds(index); // afeature that exist in the vector
    return data[index];
}

//we need to overload as we are using index access
task& List::operator[](int index) {
    checkBounds(index);
    return data[index]; //whenever we use [] this method will be called
}

int List::sizeOfList() const {
    return size;
}

bool List::isEmpty() const {
    return (size == 0);
}

//===========================================================
void List::resize(int new_capacity) {
    task* new_data = new task[new_capacity];
    for (int i=0; i<size; i++)
        new_data[i] = data[i];
    delete [] data;
    data = new_data;
    capacity = new_capacity;
}
void List::checkBounds(int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Error: index out of range");
}
