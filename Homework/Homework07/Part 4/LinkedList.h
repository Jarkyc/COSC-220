// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************

template<class T>
class ListNode {
public:
	T value;           // Node value
	ListNode<T> *next; // Pointer to the next node

	// Constructor
	ListNode(T);
};

/*
Description: ListNode default constructor
Parameters:
			(T) nodeValue: Value to assign to the node
Return: None
Notes:
*/
template<class T>
ListNode<T>::ListNode(T nodeValue){
	value = nodeValue;
	next = nullptr;
}

//*********************************************
// LinkedList class                           *
//*********************************************

template<class T>
class LinkedList {
private:
	ListNode<T> *head;   // List head pointer
	ListNode<T> *last;

public:
    unsigned long counter = 0;
	// Constructor
	LinkedList();
	LinkedList(LinkedList&);
	LinkedList& operator= (const LinkedList&);

	// Destructor
	~LinkedList();

	// Linked list operations
	void push_back(T);
	void push_front(T);
	T pop_front();
	T peakHead();
	T peakTail();
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
	void clear();
	int length();
	T get(int);
	void set(int, T);
	T& operator[] (int);
};

/*
Description: LinkedList constructor
Parameters: None
Return: None
Notes:
*/
template<class T>
LinkedList<T>::LinkedList(){
    head = nullptr; 
}

/*
Description: LinkedList Copy Constructor
Parameters:
			(LinkedList) &l: List to copy
Return: None
Notes:
*/
template<class T>
LinkedList<T>::LinkedList(LinkedList &l){
	ListNode<T> *curr = l.head;
	do {
		push_back(curr->value);
		curr = curr->next;
	}while(curr != nullptr);

}

/*
Description: Overloaded Assignment operator
Parameters:
			(LinkedList) &l: List to copy
Return: None
Notes:
*/
template<class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList &l){
	ListNode<T> *nodePtr;   // To traverse the list
	ListNode<T> *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}

	// Copy all the values

	ListNode<T> *curr = l.head;
	do {
		push_back(curr->value);
		curr = curr->next;
	}while(curr != nullptr);

	return *this;

}


/*
Description: Pushes a new value to the head of the linked list
Parameters:
			(T) newValue: New value to push
Return: None
Notes:
*/
template<class T>
void LinkedList<T>::push_front(T newValue){
	ListNode<T> *newNode = new ListNode<T>(newValue);

	newNode->next = head;
 	head = newNode;
}

//**************************************************
// push_back appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************
template<class T>
void LinkedList<T>::push_back(T newValue) {
	ListNode<T> *newNode = new ListNode<T>(newValue);

	if (head == nullptr){
		head = newNode;
		last = newNode;
	} else {
		last->next = newNode;
		last = newNode;
	}

}

/*
Description: Removes and returns the value at the head of the linked list
Parameters: None
Return:
			(T) val: value of the head
Notes:
*/
template<class T>
T LinkedList<T>::pop_front(){
	if(head == nullptr){
		string error = "Empty List Exception";
		throw error;
	} else {
		ListNode<T> *temp = head;
		head = temp->next;
		T val = temp->value;
		delete temp;
		return val;
	}
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
//**************************************************

template<class T>
void LinkedList<T>::displayList() const {
	ListNode<T> *nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr) {
		// Display the value in this node.
		cout << nodePtr->value << " ";

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template<class T>
void LinkedList<T>::insertNode(T newValue) {
	ListNode<T> *newNode;				// A new node
	ListNode<T> *nodePtr;				// To traverse the list
	ListNode<T> *previousNode = nullptr; // The previous node

	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node
	if (!head) {
		head = newNode;
		newNode->next = nullptr;
		last = newNode;
	} else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than newValue.
		while (nodePtr != nullptr && nodePtr->value < newValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		} else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

		if(previousNode == last){
			last = newNode;
		}

	}
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template<class T>
void LinkedList<T>::deleteNode(T searchValue) {
	ListNode<T> *nodePtr;       // To traverse the list
	ListNode<T> *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == searchValue) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	} else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != searchValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			if(nodePtr == last){
				last = previousNode;
			}
			delete nodePtr;
		}
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template<class T>
LinkedList<T>::~LinkedList() {
	ListNode<T> *nodePtr;   // To traverse the list
	ListNode<T> *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

/*
Description: Returns the value of the head without popping / removing it
Parameters: None
Return:
			(T) val: Value of the head
Notes:
*/
template<class T>
T LinkedList<T>::peakHead(){
	if(head == nullptr){
		string error = "Null Pointer Exception";
		throw error;
	} else {
		return head->value;
	}
}

/*
Description: Returns the value of the tail without popping / removing it
Parameters: None
Return:
			(T) val: Value of the tail
Notes:
*/
template<class T>
T LinkedList<T>::peakTail(){
	if(last == nullptr){
		string error = "Null Pointer Exception";
		throw error;
	} else {
		return last->value;
	}
}

/*
Description: Deletes everything out of the list
Parameters: None
Return: None
Notes:
*/
template<class T>
void LinkedList<T>::clear(){
	ListNode<T> *curr = head;
	ListNode<T> *temp = nullptr;

	while(curr != nullptr){
		temp = curr->next;
		delete curr;
		curr = temp;
	}

	head = nullptr;
	last = nullptr;
}

/*
Description: Returns the length of the list
Parameters: None
Return:
			(int): Length of the list
Notes:
*/
template<class T>
int LinkedList<T>::length(){
	int i = 0;
	ListNode<T> *curr = head;
	while(curr != nullptr){
		curr = curr->next;
		i++;
	}
	return i;
}

/*
Description: Returns the value at the given index. Throws error if the list is empty or the index is out of bounds
Parameters:
			(int) ind: index to check
Return:
			(T): Value at the node
Notes:
*/
template<class T>
T LinkedList<T>::get(int ind){
	ListNode<T> *curr = head;
	if(curr == nullptr){
		string err = "Empty List Exception";
		throw err;
	} else {
		if(ind < 0 || ind > length() - 1){
			string err = "Index Out of Bounds Exception";
			throw err;
		} else {
			for(int i = 0; i < ind; i++){
				curr = curr->next;
			}
			return curr->value;
		}
	}
}

/*
Description: Sets the value at the node. Throws an error if the list is empty or the index is out of bounds
Parameters:
			(int) ind: Index to set the value at
			(T) val: Value to set the node to
Return: None
Notes:
*/
template<class T>
void LinkedList<T>::set(int ind, T val){
	ListNode<T> *curr = head;
	if(curr == nullptr){
		string err = "Empty List Exception";
		throw err;
	} else {
		if(ind < 0 || ind > length() -1){
			string err = "Index Out of Bounds Exception";
			throw err;
		} else {
			for(int i = 0; i < ind; i++){
				curr = curr->next;
			}
			curr->value = val;
		}
	}
}

/*
Description: Overloaded bracket operator
Parameters:
			(int) ind: Index of node to access
Return:
			(T): Referenced value at the node
Notes:
*/
template<class T>
T& LinkedList<T>::operator[] (int ind){
	ListNode<T> *curr = head;
	if(curr == nullptr){
		string err = "Empty List Exception";
		throw err;
	} else{
		if(ind < 0 || ind > length() - 1){
			string err = "Index Out of Bounds Exception";
			throw err;
		} else {
			for(int i = 0; i< ind; i++){
				curr = curr->next;
			}
			return curr->value;
		}
	}
}
#endif
