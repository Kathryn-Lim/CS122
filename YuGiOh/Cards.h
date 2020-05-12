#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

template <class X>
class Cards {
	int ATK, DEF; //attack points and defense points of the card
	string name; //card name

public:
	//constructor
	Cards(X);

	//destructor
	~Cards();

	//copy constructor
	Cards(int, int, string);


	//setter for name of monster
	void setname(string n);
	//setter for attack points

	void setatk(int a);

	//setter for defense points
	void setdef(int d);

	//getter for attack point
	int getatk();

	//getter for defense points
	int getdef();

	//getter for card name
	string getname();

	//getter for pointer
	Cards<X>* getptr(Cards* ptr);

	//sets details of cards
	Cards<X>* setdeets();

	//adds new node
	Cards<X>* addnode(string n, int a, int d);

	Cards<X>* node();
};




#endif

