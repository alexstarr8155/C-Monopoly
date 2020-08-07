#include "Property.h"

#include <iostream>

using namespace std;

Property::Property (string & name, int price, int base_rent): Cell{name}, price{price}, rent{base_rent} {
	owned = false;
	mortgaged = false;
}

int Property::getPrice () const {
	return price;
}

bool Property::is_mortgaged () const {
	return mortgaged;
}

void Property::setOwner (shared_ptr<Player> p){
	owner = p;
}

shared_ptr<Player> getOwner () const {
	return owner;
}

void mortgage () {
	mortgaged = true;
}

void unmortgage () {
	mortgaged = false;
}

void action (shared_ptr<Player> p, bool p){
	cout << "this is my action :)" << endl;
}

