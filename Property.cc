#include <iostream>
#include <stdexcept>
#include "Property.h"
#include "Player.h"
using namespace std;

// contructor for the Property class
Property::Property(const string & name, int purchase, vector<string> set) : Cell{name}, purchase_cost{purchase} {

	owned = false;
	mortgaged = false;
	
	for (auto it = set.begin(); it != set.end(); ++it){
		set_ownership.emplace ((*it), 'z'); //'z' is the default/null owner
	}
	numImprovements = 0;
}

// mortgages the property
void Property::mortgage() {
	if (!mortgaged) {
		std::cout << owner->getMoney() << std::endl;
		mortgaged = true;
	} else {
		throw " is already mortgaged";
	}
}

// returns the price of the property (for net worth calculation)
// Note: overridden in the improvableProperty class
int Property::getValue() const {
	return purchase_cost;
}

// states that the property (gym or residence) cannot have an improvement upgrade
// Note: overridden in the improvableProperty class
void Property::upgrade() {
	cout << name << " Cannot be upgraded" << endl;
}

// states that the property (gym or residence) cannot have an improvement downgrade
// Note: overridden in the improvableProperty class
void Property::downgrade() {
	cout << name << " Cannot be downgraded" << endl;
}

// updates the on_cell member that there is a player on such cell
// if the property is not owned will ask the player that landed on it if they would like to buy the property
// if the property is not bought it will be auctioned
// if the property is owned by the player landing on it, do nothing
// if the property is owned by a player other than the player landing on it, the player landing must pay the owner
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
				if ( cin.fail () ) {
					break;
				}
				cout << "Please enter Y/N" << endl;
				cin >> in;
			}
		}
	}
	else if (p->getPlayerChar() == owner->getPlayerChar()){
		return;
	}
	else {
		cout << p->getPlayerName() << " is paying " << owner->getPlayerName() << " $" << getRent() << endl;
		p->pay(owner, getRent());
	}
}

// returns the price of the property
int Property::getPrice() const {
	return purchase_cost;
}

// will unmortgage the property only if the property is mortgaged in the first place
void Property::unmortgage() {
	if (!mortgaged) {
		std::cout << name << "is already unmortgaged" << std::endl;
		return;
	}

	if (owner->getMoney() < purchase_cost * 0.6) {
		std::cout << "You do not have enough money to unmortgage this property" << std::endl;
		return;
	}
	mortgaged = false;
}

// sets the owner of the property given a Player pointer
void Property::setOwner(Player* p) {
	if (p == nullptr) {
		owned = false;
	} else {
		owned = true;
	}
	owner = std::make_shared<Player>(*p);
}

// sets the owner of the property given a Player shared pointer
void Property::setOwner(shared_ptr<Player> p) {
	if (p == nullptr) {
		owned = false;
	} else {
		owned = true;
	}
	owner = p;
}

// Observer and Subject method implementations
void Property::attach(Property * o) {
	observers.push_back(o);
}

void Property::notifyObservers() {

	for (unsigned i = 0; i < observers.size(); i++) {
		observers[i]->notify(*this);
	}
}

void Property::notify(Property & whoNotified) {
	set_ownership.at(whoNotified.getName()) = whoNotified.getOwner()->getPlayerChar();
}
