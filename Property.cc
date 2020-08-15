#include "Property.h"
#include "Player.h"

#include <iostream>
#include <stdexcept>
using namespace std;

Property::Property (const string & name, int purchase, vector<string> set):
       	Cell{name}, purchase_cost{purchase} {

	owned = false;
	mortgaged = false;
	
	for (auto it = set.begin(); it != set.end(); ++it){
		set_ownership.emplace ((*it), 'z'); //'z' is the default/null owner
	}
	numImprovements = 0;
}

int Property::getPrice () const {
	return purchase_cost;
}

/* the commented is moved to Cell
void Property::setOwner (shared_ptr<Player> p){
	owner = p;
}

shared_ptr<Player> Property::getOwner () {
	return owner;
}
*/

void Property::mortgage () {
	if (!mortgaged) {
		std::cout << owner->getMoney() << std::endl;
		//owner->addMoney(purchase_cost/2);
//		std::cout << ", " << owner.get() << std::endl;
		mortgaged = true;
	} else {
		throw " is already mortgaged";
	}
}

void Property::unmortgage () {
	if (!mortgaged) {
		std::cout << name << "is already unmortgaged" << std::endl;
		return;
	}

	if (owner->getMoney() < purchase_cost * 0.6) {
		std::cout << "You do not have enough money to unmortgage this property" << std::endl;
		return;
	}
//	owner->removeMoney(purchase_cost*0.6);
	mortgaged = false;
}

int Property::getValue () const {
	return purchase_cost;
}

void Property::upgrade (){
        cout << name << " Cannot be upgraded" << endl;
}

void Property::downgrade (){
        cout << name << " Cannont be downgraded" << endl;
}

void Property::setOwner(Player* p) {
	if (p == nullptr) {
		owned = false;
	} else {
		owned = true;
	}
	owner = std::make_shared<Player>(*p);
}

void Property::setOwner (shared_ptr<Player> p) {
	if (p == nullptr) {
		owned = false;
	} else {
		owned = true;
	}
	owner = p;
}

void Property::action (shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;

	if (!owned) {
		cout << "Would you like to buy " << name << "? (Y/N)" << endl;
		string in;
		cin >> in;
		while (true){
			if (in == "Y" || in == "y"){
				try {
					p->buy(this);
				}
				catch (...) {
					cout << "Not enough money" << endl;
					break;
				}
				owned = true;
				owner = p;
				set_ownership.at(name) = p->getPlayerChar();
				notifyObservers();
				break;
			}
			else if (in == "N" || in == "n"){
				// auction the property
				throw invalid_argument("Auction time!");
			}
			else {
				cout << "Please enter Y/N" << endl;
			}
		}
	}
	else if (p->getPlayerChar() == owner->getPlayerChar()){
		return;
	}
	else {
		cout << p->getPlayerName () << " is paying " << owner->getPlayerName() << " $" << getRent() << endl;
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
