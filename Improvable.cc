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

/* commented was moved to property
void ImprovableProperty::upgrade (int num){
	numImprovements += num;
}

void ImprovableProperty::downgrade (int num){
	numImprovements -= num;
}
*/

int ImprovableProperty::getValue () const {
	return purchase_cost + improv_cost * numImprovements; 
}


int ImprovableProperty::getRent () const {
	
	if (numImprovements > 0) {
		return tuition.at(numImprovements);
	}

	if (set_ownership.begin()->second == 'z') {
		return tuition.at(0);
	}

	for (auto it = set_ownership.begin(); it != set_ownership.end(); ++it){
		
		if (it->second != owner->getPlayerChar()){
			return tuition.at(0);
		}
	}

	return tuition.at(0) * 2;
}

