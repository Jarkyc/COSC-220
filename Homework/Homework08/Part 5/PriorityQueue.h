#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class PQNode {
public:
    T data;
    int priority;

    PQNode(T Data) {
        data = Data;
        priority = 1;
    }

    PQNode(T Data, int Priority) {
        data = Data;
        if (Priority < 1)
            Priority = 1;

        priority = Priority;
    }
};

template<class T>
class PriorityQueue {
private:
    vector<PQNode<T> > queue; // The vector holding all of the items in the queue.

public:
    // Constructors and Destructor
    PriorityQueue();
    PriorityQueue(const PriorityQueue &obj);
    ~PriorityQueue();

    // Acessors and Mutators
    void enqueue(T Data, int Priority = 1);
    T dequeue();

    // Other Functions
    void print();
    bool isEmpty();
    void clear();
    int size();
};

/*
Description: Constructor for PriorityQueue. Does nothing.
Parameters:
Return:
Notes:
*/
template <class T>
PriorityQueue<T>::PriorityQueue(){
}

/*
Description: Copy constructor. Copies over queue information from obj.
Parameters:
            const (PriorityQueue) &obj: PriorityQueue to copy from
Return:
Notes:
*/
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj){
    queue = obj.queue;
}

/*
Description: Deconstructor. Does nothing.
Parameters:
Return:
Notes:
*/
template <class T>
PriorityQueue<T>::~PriorityQueue(){
}

/*
Description: Creates a new PQNode of the assigned data type, and gives it a priority if specified. If no priority is input, default value of 1 is assigned. Pushes node into the vector
Parameters:
            (T) Data: Data to insert
            (int) Priority: Priority to assign the data
Return:
Notes:
*/
template <class T>
void PriorityQueue<T>::enqueue(T Data, int Priority){
    PQNode<T> node(Data, Priority);
    queue.push_back(node);
}

/*
Description: Returns the highest priority value closest to the front of the queue
Parameters:
Return:
        (T) val: Value at the node
Notes:
*/
template <class T>
T PriorityQueue<T>::dequeue(){
    if(queue.size() == 0){
        T val;
        return val;
    } else {
        for(int p = 3; p > 0; p--){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                if(queue[i].priority == p){
                    T val = queue[i].data;
                    queue.erase(queue.begin()+i);
                    return val;
                }
            }
        }
    }
}

/*
Description: Prints out the queue list along with priorities od the data
Parameters:
Return:
Notes:
*/
template <class T>
void PriorityQueue<T>::print(){
    int size = queue.size();
    for(int i = 0; i < size; i++){
        cout << queue[i].data << " --- " << queue[i].priority << endl;
    }
}

/*
Description: Returns whether or not the queue is empty
Parameters:
Return:
            (bool): Whether or not the queue is empty
Notes:
*/
template <class T>
bool PriorityQueue<T>::isEmpty(){
    return queue.size() == 0;
}

/*
Description: Deletes and clears everything out of the vector
Parameters:
Return:
Notes:
*/
template <class T>
void PriorityQueue<T>::clear(){
    queue.clear();
}

/*
Description: Returns the size of the queue
Parameters:
Return:
            (int) size: Size
Notes:
*/
template <class T>
int PriorityQueue<T>::size(){
    return queue.size();
}


#endif
