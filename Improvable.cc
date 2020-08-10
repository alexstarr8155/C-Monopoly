#include "Improvable.h"

#include <iostream>

using namespace std;


ImprovableProperty::ImprovableProperty (const string &name, int p, int u, vector<string> set, vector<int> tuition):
       	Property{name, p, u, set} {

	for (auto it = tuition.begin (); it != tuition.end (); ++ it) {
		this->tuition.emplace_back(*it);
	}
	numImprovements = 0;
}

int ImprovableProperty::getNumImprov () const {
	return numImprovements;
}

void ImprovableProperty::upgrade (int num){
	numImprovements += num;
}

void ImprovableProperty::downgrade (int num){
	numImprovements -= num;
}

int ImprovableProperty::getValue () const {
	return purchase_cost; //temp, add calc later
}


int ImprovableProperty::getRent () const {
	
	if (set_ownership.begin()->second == 'z') {
		return tuition.at(0);
	}

	for (auto it = set_ownership.begin(); it != set_ownership.end(); ++it){
		
		if (it->second != (set_ownership.begin()->second) ){
			return tuition.at(0);
		}
	}

	return tuition.at(0) * 2; //temp, add calculations later
}

