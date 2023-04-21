<<<<<<< HEAD
#include "Queue.h"
#include "Stack.h"
=======
/*
Author: Charles Reigle
Creation Date: 4/20/23
Last Update: 4/20/23
Description: Pascals triangle calculator
User Interface: Enter in n and k to find out what n choose k is equal to
Notes:
*/

>>>>>>> master
#include <iostream>

using namespace std;

<<<<<<< HEAD
template <class T> void checkEmpty(Queue<T>);
template <class T> void checkEmpty(Stack<T>);

int main() {
    Stack<double> dstack;

    checkEmpty(dstack);
    cout << endl;

    dstack.push(7);
    dstack.push(25);
    dstack.push(-4);
    dstack.push(3);

    dstack.displayStack();
    cout << endl;

    checkEmpty(dstack);
    cout << endl;

    try {
        cout << dstack.pop() << endl;
        cout << dstack.pop() << endl;
        cout << endl;
    } catch (string s) {
        cout << s << endl;
    }

    dstack.push(74);
    dstack.push(2);
    dstack.push(14);

    dstack.displayStack();
    cout << endl;

    try {
        cout << dstack.pop() << endl;
        cout << dstack.pop() << endl;
        cout << dstack.pop() << endl;
        cout << dstack.pop() << endl;
        cout << dstack.pop() << endl;
        cout << dstack.pop() << endl;
    } catch (string s) {
        cout << s << endl;
    }

    dstack.displayStack();
    cout << endl;

    checkEmpty(dstack);
    cout << endl;

    for (int i = 0; i < 25; i++)
        dstack.push(i);

    dstack.displayStack();
    cout << endl;

    cout << dstack.size() << endl;
    dstack.clear();
    cout << dstack.size() << endl;
    checkEmpty(dstack);
    cout << endl;

    dstack.push(3);
    dstack.push(5);
    dstack.push(7);
    dstack.push(9);
    dstack.push(11);
    dstack.displayStack();
    cout << endl;

    Stack<double> dstack2;
    checkEmpty(dstack2);
    cout << endl;

    dstack2 = dstack;

    dstack.displayStack();
    dstack2.displayStack();
    cout << endl;

    dstack.push(3);
    dstack.push(5);
    dstack.push(7);
    dstack.push(9);
    dstack.push(11);

    dstack2.push(2);
    dstack2.push(4);
    dstack2.push(6);
    dstack2.push(8);
    dstack2.push(10);

    dstack.displayStack();
    dstack2.displayStack();
    cout << endl;

    Queue<int> iqueue;

    iqueue.enqueue(5);
    iqueue.enqueue(7);
    iqueue.enqueue(12);
    iqueue.enqueue(-23);
    iqueue.enqueue(17);

    checkEmpty(iqueue);
    cout << endl;

    iqueue.displayQueue();
    cout << endl;

    try {
        cout << iqueue.dequeue() << endl;
        cout << iqueue.dequeue() << endl;
    } catch (string s) {
        cout << s << endl;
    }

    iqueue.displayQueue();
    cout << endl;

    iqueue.enqueue(3);
    iqueue.enqueue(1);
    iqueue.enqueue(-67);
    iqueue.enqueue(32);
    iqueue.enqueue(7);

    iqueue.displayQueue();
    cout << endl;

    checkEmpty(iqueue);
    cout << endl;

    iqueue.clear();

    cout << iqueue.size() << endl;
    checkEmpty(iqueue);
    cout << endl;

    for (int i = 0; i < 25; i++)
        iqueue.enqueue(i);

    iqueue.displayQueue();
    cout << endl;

    Queue<int> iqueue2;

    iqueue2 = iqueue;

    iqueue.displayQueue();
    iqueue2.displayQueue();
    cout << endl;

    for (int i = 25; i > 0; i--)
        iqueue2.enqueue(i);

    iqueue.displayQueue();
    iqueue2.displayQueue();
    cout << endl;

    return 0;
}

template <class T> void checkEmpty(Queue<T> q) {
    if (q.isEmpty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;
}

template <class T> void checkEmpty(Stack<T> s) {
    if (s.isEmpty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;
=======
int pascal(int, int);

int main(){
    int n, k;
    cout << "Enter n and k (integer) with a space between them: ";
    cin >> n;
    cin >> k;

    cout << n << " choose " << k << " = " << pascal(n, k) << endl;

}

int pascal(int n, int k){
    // If we are starting in the beginning, the value is 1.
    if(k == 0) return 1;

    // If n is negative or = 0, or k is negative, the value is 0
    if(n <= 0 || k < 0) return 0;

    // Call pascal again to get the values of the numbers above n, k
    return pascal(n-1, k) + pascal(n-1, k-1);
>>>>>>> master
}
