#include "List.h"

template <typename T>
List<T>::List(): capacity(8), size(0) {
    data = new T[capacity];
}

template <typename T>
List<T>::List(int initial_capacity): capacity(initial_capacity), size(0) {
    data = new T[capacity];
}

template <typename T>
List<T>::~List() {
    delete[] data;
}

template <typename T>
void List<T>::push_back(const T& element) {
    if (size == capacity)
        resize(capacity*2);
    data[size++] = element; 
}

//=============================================================
template <typename T>
const T& List<T>::getter (int index) const {
    checkBounds(index); 
    return data[index];
}

template <typename T>
T& List<T>::operator[](int index) {
    checkBounds(index);
    return data[index]; 
}

template <typename T>
int List<T>::sizeOfList() const {
    return size;
}

template <typename T>
bool List<T>::isEmpty() const {
    return (size == 0);
}

//===========================================================
template <typename T>
void List<T>::resize(int new_capacity) {
    T* new_data = new T[new_capacity];
    for (int i=0; i<size; i++)
        new_data[i] = data[i];
    delete [] data;
    data = new_data;
    capacity = new_capacity;
}

template <typename T>
void List<T>::checkBounds(int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Error: index out of range");
}
