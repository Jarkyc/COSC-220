/*
Author: Charles Reigle
Creation Date: 4/17/23
Last Update: 4/17/23
Description: FIFO Queue specifications and implementation. Uses custom linked list for data storage.
Notes: Data from the queues are first in first out.
*/
#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class Queue {
private:
    LinkedList<T> queue;

public:
    Queue();
    ~Queue();
    void displayQueue(bool nl = false) const;

    Queue(const Queue &obj);
    const Queue operator=(const Queue &right);

    void clear();
    int size();
    void enqueue(T);
    T dequeue();
    bool isEmpty();
};

#endif

/*
Description: Queue constructor. Does nothing
Parameters:
Return:
Notes:
*/
template <class T>
Queue<T>::Queue(){
}

/*
Description: Queue destructor. Does nothing.
Parameters:
Return:
Notes:
*/
template <class T>
Queue<T>::~Queue(){
}

/*
Description: Lists the queue
Parameters:
            (bool) nl: Whether or not to print all that data on their own individual lines
Return:
Notes:
*/
template <class T>
void Queue<T>::displayQueue(bool nl) const{
    queue.displayList(nl);
}

/*
Description: Queue copy constructor
Parameters:
            const (Queue) &obj: Object to copy information from
Return:
Notes:
*/
template <class T>
Queue<T>::Queue(const Queue &obj){
    queue = obj.queue;
}

/*
Description: Overloaded assignment operator
Parameters:
            const (Queue) &right: Queue object to copy information from
Return:
Notes:
*/
template <class T>
const Queue<T> Queue<T>::operator= (const Queue &right){
    queue = right.queue;
    return *this;
}

/*
Description: Clears and empties the linked list
Parameters:
Return:
Notes:
*/
template <class T>
void Queue<T>::clear(){
    queue.clear();
}

/*
Description: Returns the size of the queues linked list
Parameters:
Return:
            (int): Size of list
Notes:
*/
template <class T>
int Queue<T>::size(){
    return queue.length();
}

/*
Description: Pushes input value to the back of the line
Parameters:
            (T) val: Value to insert
Return:
Notes:
*/
template <class T>
void Queue<T>::enqueue(T val){
    queue.push_back(val);
}

/*
Description: Removes from list and returns the value insert before all the others
Parameters:
Return:
        (T): Oldest value
Notes:
*/
template <class T>
T Queue<T>::dequeue(){
    return queue.pop_front();
}

/*
Description: Returns whether or not the list is empty
Parameters:
Return:
            (bool): Is the list empty?
Notes:
*/
template <class T>
bool Queue<T>::isEmpty(){
    return queue.length() == 0;
}
