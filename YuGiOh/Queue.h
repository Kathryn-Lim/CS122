//THIS IS THE MAIN DECK OF CARDS
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Cards.h"

using namespace std;
#define SIZE 10

template <class X>
class queue
{
	X *arr; 		// array to store queue elements
	int capacity;   // maximum capacity of the queue
	int front;  	// front points to front element in the queue (if any)
	int rear;   	// rear points to last element in the queue
	int count;  	// current size of the queue
	X card;			//template for Cards type

public:
	// constructor
	queue(X);
	//destructor
	~queue() {
		cout << "Queue cleared!" << endl;
	}
	//overloading constructor
	queue(int size);
	//remove front element from queue
	void dequeue();
	//add item to end of the queue
	void enqueue(X);
	//returns front element of the queue
	X peek();
	//returns size of the queue
	int size();
	//checks if queue is empty 
	bool isEmpty();
	//checks if queue is full (has 10 elements)
	bool isFull();
	//loads Cards into Queue
	void putcards();

	void runapp();
};


#endif 

