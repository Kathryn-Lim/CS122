#include "Cards.h"
//sets value for each monster card

//constructor
template <class X>
Cards<X>::Cards(X size) {
	name = "";
	ATK = 0;
	DEF = 0;
}
//destructor
template <class X>
Cards<X>::~Cards() {
	cout << "Destructor called";
}

template<class X>
Cards<X> ::Cards(int atk, int def, string n) {
	this->ATK = atk;
	this->DEF = def;
	this->name = n;
}

//setter for name of monster
template <class X>
void Cards<X>::setname(string n) {
	this->name = n;
}
//setter for attack points
template <class X>
void Cards<X>::setatk(int a) {
	this->ATK = a;
}
//setter for defense points
template <class X>
void Cards<X>::setdef(int d) {
	this->DEF = d;
}

template <class X>
int Cards<X>::getatk() {
	return this->ATK;
}

template <class X>
int Cards<X>::getdef() {
	return this->DEF;
}

template <class X>
string Cards<X>::getname() {
	return this->name;
}

template <class X>
Cards<X>* Cards<X>::getptr(Cards* ptr) {
	return ptr;
}

template <class X>
Cards<X>* Cards<X>::setdeets() {
	addnode("Blue Eyes Ultimate Dragon", 4500, 3800);
	addnode("Magician of Black Chaos", 2800, 2600);
	addnode("Palladium Oracle Mana", 2000, 1700);
	addnode("Red-Eyes Black Dragon", 2400, 2000);
	addnode("Neo Kaiser Glider", 2400, 2200);
	addnode("Obelisk the Tormentor", 4000, 4000);
	addnode("Dark Blade", 1800, 1500);
	addnode("Gaia Knight", 2600, 800);
	addnode("Blue Eyes Ultimate Dragon", 4500, 3800);
	addnode("Nibiru the Primal Being", 3000, 600);

}

//adds node
template <class X>
Cards<X>* Cards<X>::addnode(string n, int a, int d) {
	Cards* newcard = new (Cards);

	newcard->setname(n);
	newcard->setatk(a);
	newcard->setdef(d);

	return newcard;
}

