#include "Property.h"

#include <iostream>

using namespace std;

Property::Property (const string & name, int price, int base_rent): Cell{name}, price{price}, rent{base_rent} {
	owner = -1;
	owned = false;
	mortgaged = false;
}

int Property::getPrice () const {
	return price;
}

bool Property::is_mortgaged () const {
	return mortgaged;
}

void Property::setOwner (int p){
	owner = p;
}

int Property::getOwner () const {
	return owner;
}

void Property::mortgage () {
	mortgaged = true;
}

void Property::unmortgage () {
	mortgaged = false;
}

int Property::getValue () const {
	return price;
}

void Property::action (shared_ptr<Player> p, bool b){
	cout << "this is my action :)" << endl;
}

