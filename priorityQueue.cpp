#include <iostream>
#include <utility>
#include <exception>
using namespace std;

template <typename DataType>
class priorityQueue{
    //private data members
    private:
        
        //Element struct with value and priority
        struct element{ //start of struct
            DataType value;
            int priority;

            //constructor
            element() : value(), priority(0) {}

            element(const DataType& value, int priority) : value(value), priority(priority) {}

            //move constructor
            element(element&& other) noexcept 
            : value(move(other.value)), priority(other.priority) {} //noexcept tells the compiler that no excpetions will be no exceptions

            //move assignment
            element& operator=(element&& other_element){
                if(this == &other_element) return *this;

                this->value = move(other_element.value);
                this->priority = other_element.priority;

                return *this;
            }

            //copy assignment
            element& operator=(const element& other){
                if(this == &other) return *this;
                this->value = other.value;      // copy value
                this->priority = other.priority;
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
            element * newBlock = new element[newCapacity + 1]; // +1 because of 1-base indecies

            //if we are reducing the size
            if(p_size + 1 > newCapacity)
                p_size = newCapacity;

            for(int i = 1; i <= p_size; i++)
                newBlock[i] = move(maxHeap[i]);

            delete[] maxHeap;
            maxHeap = newBlock;
            p_capacity = newCapacity;
        }

        int p_parent(int i) {return i/2;}
        int p_left(int i) {return i*2;}
        int p_right(int i) {return (i*2 + 1);}

        void swap(int i, int j){
            element temp = move(maxHeap[i]);
            maxHeap[i] = move(maxHeap[j]);
            maxHeap[j] = move(temp);
        }
 
    //public functions
    public:
        priorityQueue(){
            ReAlloc(5);
        }

        //copy constructor
        priorityQueue(const priorityQueue& other){
            //copy size and capacity
            this->p_size = other.p_size;
            this->p_capacity = other.p_capacity;

            //allocate a new heap
            this->maxHeap = new element[p_capacity + 1];

            //copy each element
            for(int i = 1; i <= p_size; i++){
                this->maxHeap[i] = other.maxHeap[i];
            }
        }

        //move constructor
        priorityQueue(priorityQueue&& other){
            //copy size and capacity
            this->p_size = other.p_size;
            this->p_capacity = other.p_capacity;

            //point to the other max heap
            this->maxHeap = other.maxHeap;
            
            //free the other max heap
            other.maxHeap = nullptr;
            other.p_size = 0;
            other.p_capacity = 0;
        }

        void insert(DataType val, int priority){
            //initialize element
            element newElement(val, priority);

            //handle first insertion
            if(p_size == 0){
                maxHeap[1] = move(newElement);
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
            maxHeap[new_index] = move(newElement);
            p_size ++;

            //modify max heap after inserting
            int j = new_index;
            while(j > 1){
                int parent = p_parent(j);

                if(maxHeap[j].priority > maxHeap[parent].priority){
                    swap(j, parent);
                    j = parent;
                }
                else return;
            }
        }
        //returns the value of the top element (highest priority)
        const DataType& top() const {
            if (p_size == 0) {
                cerr << "Error: Priority queue is empty. Returning default value." << endl;
                return DataType();
            }
            return maxHeap[1].value;
        }

        //removes the top (highest priority) element from the queue
        void pop() {
            //incase of empty queue
            if (p_size == 0) {
                return; 
            }

            //replace the root element with the last element in the heap
            maxHeap[1] = move(maxHeap[p_size]);
            p_size--;

            //modify max heap after removing (Sift Down)
            int current = 1;
            
            //continue while there is at least a left child
            while (p_left(current) <= p_size) {
                int max_child = p_left(current);
                
                //if a right child exists and > left child, update max_child
                if (p_right(current) <= p_size && maxHeap[p_right(current)].priority > maxHeap[max_child].priority) {
                    max_child = p_right(current);
                }

                //if the current element and >= largest child, we're done
                if (maxHeap[current].priority >= maxHeap[max_child].priority) {
                    break;
                }

                //o.w, swap with the largest child and continue down the tree
                swap(current, max_child);
                current = max_child;
            }
        }

        bool isEmpty() const {
            return p_size == 0;
        }
        
        ~priorityQueue(){
            delete[] maxHeap;
        }
};


int main() {
    cout << "=== Testing priorityQueue ===" << endl;

    // 1️⃣ Create a priority queue of chars
    priorityQueue<char> PQ;
    PQ.insert('a', 10);
    PQ.insert('c', 5);
    PQ.insert('k', 20);
    PQ.insert('l', 15);

    cout << "Priority queue after insertions (should print highest priority first):" << endl;
    while (!PQ.isEmpty()) {
        cout << PQ.top() << " (priority " << PQ.top() << ")" << endl; // note: top() returns value, not priority
        PQ.pop();
    }

    // 2️⃣ Test copy constructor
    priorityQueue<char> PQ2;
    PQ2.insert('x', 1);
    PQ2.insert('y', 50);
    priorityQueue<char> PQ_copy = PQ2; // copy constructor

    cout << "\nCopied queue elements:" << endl;
    while (!PQ_copy.isEmpty()) {
        cout << PQ_copy.top() << endl;
        PQ_copy.pop();
    }

    // 3️⃣ Test move constructor
    priorityQueue<char> PQ3;
    PQ3.insert('m', 10);
    PQ3.insert('n', 20);
    priorityQueue<char> PQ_moved = std::move(PQ3); // move constructor

    cout << "\nMoved queue elements:" << endl;
    while (!PQ_moved.isEmpty()) {
        cout << PQ_moved.top() << endl;
        PQ_moved.pop();
    }

    cout << "\nOriginal moved-from queue should be empty: " 
         << (PQ3.isEmpty() ? "Yes" : "No") << endl;

    // 4️⃣ Test edge case: popping from empty queue
    PQ3.pop(); // should do nothing
    cout << "Pop from empty queue did not crash." << endl;

    return 0;
}