#include <iostream>
#include "Improvable.h"
#include "Player.h"
using namespace std;

// constructor for the ImprovableProperty class
ImprovableProperty::ImprovableProperty(const string &name, int p, int u, vector<string> set, vector<int> tuition) : Property{name, p, set}, improv_cost{u} {
	
	for (auto it = tuition.begin (); it != tuition.end (); ++ it) {
		this->tuition.emplace_back(*it);
	}

	numImprovements = 0;
}

// returns a bool representing if the other one/two properties are owned by the same owner, completeting a set
bool ImprovableProperty::completeSet() const {
	for (auto it = set_ownership.begin(); it != set_ownership.end(); ++it){
		if (it->second != owner->getPlayerChar()){
			return false;
		}
	}
	return true;
}

// checks if there are no improvements on the property and if not then call the mortgage function
void ImprovableProperty::mortgage() {
	
	if (getNumImprov() > 0) {
		throw numImprovements;
	}
	Property::mortgage();
}

// adds an improvement to the property
void ImprovableProperty::upgrade() {
	if (completeSet() && numImprovements < 5){
		try {
			owner->removeMoney(improv_cost);
			numImprovements++;
		}
		catch (...) {
			cout << owner->getPlayerName() << " does not have enough money to improve " << name << endl;
		}
	}
	else if (!completeSet()){
		cout << "You need the whole set to improve a property" << endl;
	}
	else if (numImprovements >= 5){
		cout << "You cannot improve any more" << endl;
	}
}

// removes an improvement to the property
void ImprovableProperty::downgrade() {
	if (numImprovements > 0) {
		numImprovements--;
		owner->addMoney(improv_cost / 2);
	}
	else { 
		cout << "There are no improvements on this property" << endl;
	}
}

// returns the rent that players will have to pay
int ImprovableProperty::getRent() const {
	
	if (numImprovements > 0) {
		return tuition.at(numImprovements);
	}

	if (set_ownership.begin()->second == 'z') {
		return tuition.at(0);
	}

	if (!completeSet()){
		return tuition.at(0);
	}

	return tuition.at(0) * 2;
}

// returns the property value (for Net Worth)
int ImprovableProperty::getValue() const {
	return purchase_cost + improv_cost * numImprovements; 
}
