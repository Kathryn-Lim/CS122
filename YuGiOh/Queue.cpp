#include "Queue.h"

template <class X>
queue<X>::queue(X size) {
	arr = new X[10];
	capacity = 10;
	front = 0;
	rear = -1;
	count = 0;
}

template <class X>
queue<X>::queue(int size)
{
	arr = new X[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

template <class X>
void queue<X>::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
}

template <class X>
void queue<X>::enqueue(X card)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << card.name << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = card;
	count++;
}

template <class X>
X queue<X>::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	else {
		cout << arr[front].name;
	}
	return arr[front];
}

template <class X>
int queue<X>::size()
{
	return count;
}

template <class X>
bool queue<X>::isEmpty()
{
	return (size() == 0);
}

template <class X>
bool queue<X>::isFull()
{
	return (size() == capacity);
}

//put one card class into enqueue one by one
template <class X>
void queue<X>::putcards() {
	int i = 0;
	//creates queue of capacity 10 for 10 cards (initiailzes the deck of cards)
	queue<Cards> q(10);

	for (i = 0; i < 9; ++i) {
		q.enqueue(card);
	}

	cout << "There are currently " << count << " cards in the deck" << endl;
	cout << "this is peek test: " << peek();
}

template <class X>
void queue<X>::runapp() {
	putcards();
}

