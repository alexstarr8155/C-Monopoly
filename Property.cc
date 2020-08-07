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

shared_ptr<Player> Property::getOwner () {
	return owner;
}

void Property::mortgage () {
	mortgaged = true;
}

void Property::unmortgage () {
	mortgaged = false;
}

void Property::action (shared_ptr<Player> p, bool b){
	cout << "this is my action :)" << endl;
}

