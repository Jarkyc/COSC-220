/*
Author: Charles Reigle
Creation Date: 4/17/23
Last Update: 4/17/23
Description: LIFO Stack specifications and implementation. Uses custom LinkedList for data storage.
Notes: Data from the stack is last inserted object is first out
*/
#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class Stack {
private:
    LinkedList<T> stack;

public:
    Stack();
    ~Stack();
    void displayStack(bool nl = false) const;

    Stack(const Stack &obj);
    const Stack operator=(const Stack &right);

    void clear();
    int size();
    void push(T);
    T pop();
    bool isEmpty();
};

#endif

/*
Description: Constructor. Does nothing
Parameters:
Return:
Notes:
*/
template <class T>
Stack<T>::Stack(){
}

/*
Description: Destructor. Does nothing
Parameters:
Return:
Notes:
*/
template <class T>
Stack<T>::~Stack(){
}

/*
Description: Prints out the linked list stack
Parameters:
            (bool) nl: Whether or not to create a new line after each value
Return:
Notes:
*/
template <class T>
void Stack<T>::displayStack(bool nl) const{
    stack.displayList(nl);
}

/*
Description: Copy constructor. Copies over data from the assigned object
Parameters:
            const (Stack) &obj: Stack object to copy from
Return:
Notes:
*/
template <class T>
Stack<T>::Stack(const Stack &obj){
    stack = obj.stack;
}

/*
Description: Overloaded assignment operator
Parameters:
            const (Stack) &right: Stack object to copy from
Return:
            (Stack) the new copied stack
Notes:
*/
template <class T>
const Stack<T> Stack<T>::operator=(const Stack &right){
    stack = right.stack;
    return *this;
}

/*
Description: Deletes all data from the stack
Parameters:
Return:
Notes:
*/
template <class T>
void Stack<T>::clear(){
    stack.clear();
}

/*
Description: Returns the size of the list
Parameters:
Return:
            (int): Size of the stack list
Notes:
*/
template <class T>
int Stack<T>::size(){
    return stack.length();
}

/*
Description: Pushes a new item to the front of the list
Parameters:
            (T) val: Value to push
Return:
Notes:
*/
template <class T>
void Stack<T>::push(T val){
    stack.push_front(val);
}

/*
Description: Removes and returns the most recently pushed item in the list
Parameters:
Return:
            (T): Value at the top of the stack
Notes:
*/
template <class T>
T Stack<T>::pop(){
    return stack.pop_front();
}

/*
Description: Returns whether or not the stack is empty
Parameters:
Return:
            (bool): Empty or not
Notes:
*/
template <class T>
bool Stack<T>::isEmpty(){
    return stack.length() == 0;
}
