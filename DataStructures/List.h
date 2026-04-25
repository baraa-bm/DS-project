#ifndef ADS_PROJECT_LIST_H
#define ADS_PROJECT_LIST_H
#include <stdexcept>

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
    T& operator[](int); 
    int sizeOfList() const;
    bool isEmpty() const;
};

#include "List.tpp" 
#endif //ADS_PROJECT_LIST_H