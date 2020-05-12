#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class GameWorld {
	//the game board
	char state[5][5] = { {' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' '}
						};
	int playerpts=0;

public:
	//constructor
	GameWorld() {}

	//destructor
	~GameWorld() {}

	//getters and setters
	//returns tokens on board
	char getstate(int x, int y);

	//sets state
	void setstate(int x, int y);

	//returns player points
	int getplayerpoints();

	//sets playerpoints
	void setplayerpoints(int x);

	//functions
	//displays entire world
	void displayEntireWorld();

	//displays all squares one square away from P
	//precond: array pos. assigned for W,U,P,G,		array pos. for U
	//postcond: none
	void displayVisibleWorld(GameWorld P);

	//moves P up one square
	void moveUp();

	//moves P down one square
	void moveDown();

	//moves P right one square
	void moveRight();

	//moves P left one square
	void moveLeft();

	//checks status if P wins. Return true if won, false if lost
	bool haveIWon();

	//checks if player hit Wumpus or pit (isalive). True if not hit, false if hit
	bool amIAlive();

	//randomizes wumpus postion at start, return pointer to wumpus location
	char* randomize(GameWorld g);

};

class Player :public GameWorld {
	int points;

public:
	Player();

	~Player();

	int getpoints();

	void setpoints(int x);
};


	//main interface of the game
	void mi();


#endif
