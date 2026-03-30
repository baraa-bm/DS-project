#ifndef ADS_PROJECT_LIST_H
#define ADS_PROJECT_LIST_H
#include <stdexcept>

//it is an implementation for the vector like operations
template <typename T>
class List {
private:
    T* data;
    int capacity;
    int size;

    void resize(int);
    void checkBounds(int) const;

public:
    List();
    List(int);
    ~List();

    void push_back(const T &element);
    const T& getter (int) const;
    T& operator[](int); //operator overloading as we get the element using index based.
    int sizeOfList() const;
    bool isEmpty() const;
};

#include "List.cpp" // include template implementation
#endif //ADS_PROJECT_LIST_H