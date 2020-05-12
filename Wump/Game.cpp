#include "Game.h"
//row=x column = y

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::displayEntireWorld(){
	cout << "\t\t	|	|	|	|	" << endl;
	cout << "\t\t   " << getstate(0, 0) << "	|  " << getstate(0, 1) << "	|  " << getstate(0, 2) << "	|  " << getstate(0, 3) << "	|  " << getstate(0, 4) << endl;
	cout << "\t\t________|_______|_______|_______|_______" << endl;
	cout << "\t\t	|	|	|	|	" << endl;
	cout << "\t\t   " << getstate(1, 0) << "	|  " << getstate(1, 1) << "	|  " << getstate(1, 2) << "	|  " << getstate(1, 3) << "	|  " << getstate(1, 4) << endl;
	cout << "\t\t________|_______|_______|_______|_______" << endl;
	cout << "\t\t	|	|	|	|	" << endl;
	cout << "\t\t   " << getstate(2, 0) << "	|  " << getstate(2, 1) << "	|  " << getstate(2, 2) << "	|  " << getstate(2, 3) << "	|  " << getstate(2, 4) << endl;
	cout << "\t\t________|_______|_______|_______|_______" << endl;
	cout << "\t\t	|	|	|	|	" << endl;
	cout << "\t\t   " << getstate(3, 0) << "	|  " << getstate(3, 1) << "	|  " << getstate(3, 2) << "	|  " << getstate(3, 3) << "	|  " << getstate(3, 4) << endl;
	cout << "\t\t________|_______|_______|_______|_______" << endl;
	cout << "\t\t	|	|	|	|	" << endl;
	cout << "\t\t   " << getstate(4, 0) << "	|  " << getstate(4, 1) << "	|  " << getstate(4, 2) << "	|  " << getstate(4, 3) << "	|  " << getstate(4, 4) << endl;
	cout << "\t\t	|	|	|	|	" << endl;
}

void GameWorld::displayVisibleWorld(GameWorld P){

}

void GameWorld::moveUp() {}

void GameWorld::moveDown() {}

void GameWorld::moveRight() {}

void GameWorld::moveLeft() {}

bool GameWorld::haveIWon() {}

bool GameWorld::amIAlive(){}

char GameWorld::getstate(int x, int y) {

	return state[x][y];
}

void GameWorld::setstate(int x, int y) {

	this->state[x][y];
	return;
}

int GameWorld::getplayerpoints() {
	return playerpts;
}

void GameWorld::setplayerpoints(int x) {
	this->playerpts = x;
	return;
}

char* GameWorld::randomize(GameWorld g) {
	char *arr = NULL;
	int x, y;
	x = rand() % 4 + 0;
	y = rand() % 4 + 0;

	g.setstate(x, y);

	
}

void mi() {
	Player p1;

	cout << "\t\t\tHUNT THE WUMPUS" << endl;
	cout << "Player Points: "<<p1.getplayerpoints() << endl;


}

Player::Player() {
	points = 0;
}

Player::~Player() {}

int Player::getpoints() {
	return this->points;
}

void Player::setpoints(int x) {
	this->points = x;
}