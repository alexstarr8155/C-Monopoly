#include "Improvable.h"
#include "Player.h"

#include <iostream>

using namespace std;


ImprovableProperty::ImprovableProperty (const string &name, int p, int u, vector<string> set, vector<int> tuition):
       	Property{name, p, set}, improv_cost{u} {

	for (auto it = tuition.begin (); it != tuition.end (); ++ it) {
		this->tuition.emplace_back(*it);
	}
	numImprovements = 0;
}

int ImprovableProperty::getNumImprov () const {
	return numImprovements;
}


void ImprovableProperty::upgrade (){
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

void ImprovableProperty::downgrade (){
	if (numImprovements > 0) {
		numImprovements--;
		owner->addMoney(improv_cost / 2);
	}
	else { 
		cout << "There are no improvements on this property" << endl;
	}

}


int ImprovableProperty::getValue () const {
	return purchase_cost + improv_cost * numImprovements; 
}


bool ImprovableProperty::completeSet () const {
	for (auto it = set_ownership.begin(); it != set_ownership.end(); ++it){
		if (it->second != owner->getPlayerChar()){
			return false;
		}
	}
	return true;
}

int ImprovableProperty::getRent () const {
	
	if (numImprovements > 0) {
		return tuition.at(numImprovements);
	}

	if (set_ownership.begin()->second == 'z') {
		return tuition.at(0);
	}
/*
	for (auto it = set_ownership.begin(); it != set_ownership.end(); ++it){
		
		if (it->second != owner->getPlayerChar()){
			return tuition.at(0);
		}
	}
*/
	if (!completeSet()){
		return tuition.at(0);
	}

	return tuition.at(0) * 2;
}

void ImprovableProperty::mortgage() {
	
	if (getNumImprov() > 0) {
		throw "There are improvements on the property, sell them before mortgaging";
	}
	Property::mortgage();

}






