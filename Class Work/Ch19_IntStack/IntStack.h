// Specification file for the IntStack class
// Stacks are Last in First Out
#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack {
private:
	int *stackArray;  // Pointer to the stack array
	int stackSize;    // The stack size
	int top;          // Indicates the top of the stack. This is the index. If there is nothing in the stack, maybe set the index to -1.

public:
	// Constructor
	IntStack(int);

	// Copy constructor
	IntStack(const IntStack&);

	// Destructor
	~IntStack();

	// Stack operations
	void push(int);
	void pop(int&);
	bool isFull() const;
	bool isEmpty() const;
};
#endif 
