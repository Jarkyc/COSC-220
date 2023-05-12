#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

/*
 Author: Don Spickler
 Creation Date: 4/6/2023
 Last Update: 4/6/2023
 Description:  Templated Priority Queue class that uses the STL vector as the underlying
 storage structure.
 Note: The template class T must
 1. overloaded =
 2. Have a default constructor
 3. Overloaded >>
 4. Copy Constructor
 */

using namespace std;

// Node data type that holds the data and 
// priority of the item.

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

	PQNode<T>& operator[](const int&);
};

/*
 Description: Constructor
 Note: Everything is taken care of through the STL vector.
 */

template<class T>
PriorityQueue<T>::PriorityQueue() {
}

/*
 Description: Copy Constructor
 Parameters: obj - PriorityQueue object to be copied.
 Note: Everything is taken care of through the STL vector's overloaded =.
 */

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj) {
	queue = obj.queue;
}

/*
 Description: Destructor
 Note: Everything is taken care of through the STL vector.
 */

template<class T>
PriorityQueue<T>::~PriorityQueue() {
}

/*
 Description: Adds the data to the queue with the input priority.
 Parameters:
 Data - templated type to be added to queue.
 Priority - integer priority level.  Larger values repesent greater priority.
 */

template<class T>
void PriorityQueue<T>::enqueue(T Data, int Priority) {
	PQNode<T> node(Data, Priority);
	queue.push_back(node);
}

/*
 Description: Dequeues the first element of the highest priority from the queue.
 Return: The first element of the highest priority in the queue.
 */

template<class T>
T PriorityQueue<T>::dequeue() {
	if (queue.empty()) {
		T defaultObj;
		return defaultObj;
	}

	int maxpriority = 0;
	for (unsigned int i = 0; i < queue.size(); i++)
		if (maxpriority < queue[i].priority)
			maxpriority = queue[i].priority;

	int pos = 0;
	while (maxpriority != queue[pos].priority)
		pos++;

	T saveData = queue[pos].data;
	queue.erase(queue.begin() + pos);
	return saveData;
}

/*
 Description: Prints the queue data and associated priority to cout.  Each element is printed on its own line.
 */

template<class T>
void PriorityQueue<T>::print() {
	for (unsigned int i = 0; i < queue.size(); i++)
		cout << queue[i].data << "  ---  " << queue[i].priority << endl;
}

/*
 Description: Checks if queue is empty.
 Return: true if the queue is empty and false if there are elements in the queue.
 */

template<class T>
bool PriorityQueue<T>::isEmpty() {
	return queue.empty();
}

/*
 Description:  Removes all elements from the queue.
 */

template<class T>
void PriorityQueue<T>::clear() {
	queue.clear();
}

/*
 Description: Returns the number of elements in the queue.
 Return: The number of elements in the queue.
 */

template<class T>
int PriorityQueue<T>::size() {
	return queue.size();
}

/*
 Description: Overloaded [] operator.  Returns the elements at position pos in the queue.
 Parameters: pos - posittion of the element to be returned.
 Return: The pos element in the queue.
 */

template<class T>
PQNode<T>& PriorityQueue<T>::operator[](const int &pos) {
	if (pos < 0)
		return queue[0];

	if (pos >= queue.size())
		return queue[queue.size() - 1];

	return queue[pos];
}

#endif
