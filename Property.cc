#include "Property.h"
#include "Player.h"

#include <iostream>

using namespace std;

Property::Property (const string & name, int price, int base_rent): Cell{name}, price{price}, rent{base_rent} {
	owned = false;
	mortgaged = false;

	set_ownership = {
		{"MC", 'z'},
		{"DC", 'z'} };
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

int Property::getValue () const {
	return price;
}

int Property::getRent () const {
	return rent;
}

// If b == True, then player wants to buy the property 
// If b == False, then:
// 			If this is owned, then p pays rent to owner
// 			If not, then nothing happens
//
// on_cell is always updated
void Property::action (shared_ptr<Player> p, bool b){
	on_cell.at(p->getPlayerChar()) = true;

	if (b){
		owner = p;
		p->buy(std::make_shared<Property>(*this));
		set_ownership.at(name) = p->getPlayerChar ();
		notifyObservers();
	}
	else if (owner){
		p->pay(owner, getRent());
	}

}


void Property::notify (Subject & s) {
	
	set_ownership.at(s.getName()) = s.getOwner()->getPlayerChar();
}
