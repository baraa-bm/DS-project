#include <iostream>
using namespace std;

template <typename DataType>
class priorityQueue{
    //private data members
    private:
        
        //Element struct with value and priority
        struct element{ //start of struct
            DataType value;
            int priority = 0;

            //constructor
            element() : value() {}

            element(const DataType& value, int priority = 0) : value(value), priority(priority) {}

            //equal operator overload
            element& operator = (const element& other_element){
                this->value = other_element.value;
                this->priority = other_element.priority;

                return *this;
            }

        }; //end of struct
        
        //max heap representing the priority queue
        element * maxHeap = nullptr;

        int p_size = 0; //current size occupied
        int p_capacity = 0; //max_size
        
    //private functions    
    private:
        void ReAlloc(int newCapacity){
            // 1. allocate a new block of memory
            // 2. copy/move old elements into new block
            // 3. delete
            element * newBlock = new element[size];

            //if we are reducing the size
            if(p_size > newCapacity)
                p_size = newCapacity;

            for(int i = 0; i < p_size; i++)
                newBlock[i] = maxHeap[i];

            delete[] maxHeap;
            maxHeap = newBlock;
            p_capacity = newCapacity;
        }

        int p_parent(int i) {return i/2;}
        int p_left(int i) {return i*2;}
        int p_right(int i) {return (i*2 + 1);}

        void swap(int i, int j){
            element temp = maxHeap[i];
            maxHeap[i] = maxHeap[j];
            maxHeap[j] = temp;
        }
 
    //public functions
    public:
        priorityQueue(){
            ReAlloc(5);
        }

        void insert(DataType val){
            //initialize element
            element newElement(val);

            //handle first insertion
            if(p_size == 0){
                maxHeap[1] = newElement;
                p_size ++;
                return;
            }

            //if a resize is needed
            if(p_size >= p_capacity){
                ReAlloc(p_capacity + p_capacity/2);
            }

            //index of the new element
            int new_index = p_size + 1; 

            //insert new element
            maxHeap[new_index] = newElement;
            p_size ++;

            //modify max heap after inserting
            int j = new_index;
            while(j > 1){
                int parent = p_parent(j);

                if(maxHeap[j].value > maxHeap[parent].value){
                    //update priority
                    maxHeap[j].priority += 1;
                    swap(j, parent);
                    j = parent;
                }
                else return;
            }
        }

        DataType pop();
        DataType top();
        
};