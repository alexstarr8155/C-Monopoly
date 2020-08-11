#include "Property.h"
#include "Player.h"

#include <iostream>

using namespace std;

Property::Property (const string & name, int purchase, int upgrade, vector<string> set):
       	Cell{name}, purchase_cost{purchase}, up_cost{upgrade} {

	owned = false;
	mortgaged = false;
	
	for (auto it = set.begin(); it != set.end(); ++it){
		set_ownership.emplace ((*it), 'z'); //'z' is the default/null owner
	}
}

int Property::getPrice () const {
	return purchase_cost;
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
	return purchase_cost;
}


int Property::getRent () const {
	return 0;
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
		owned = true;
		owner = p;
		p->buy(this);
		set_ownership.at(name) = p->getPlayerChar ();
		notifyObservers();
	}
	else if (owner){
		p->pay(owner, getRent());
	}

}



// Observer and Subject method implementations
void Property::attach(Property * o) {
	observers.push_back(o);
}

void Property::notifyObservers() {

	for (int i = 0; i < observers.size(); i++) {
		observers[i]->notify(*this);
	}
}

void Property::notify (Property & whoNotified) {
	set_ownership.at(whoNotified.getName()) = whoNotified.getOwner()->getPlayerChar();
}
