#include "Improvable.h"

#include <iostream>

using namespace std;


ImprovableProperty::ImprovableProperty (const string &name, int price, int base_rent) : Property{name, price, base_rent} {
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
	return price; //temp, add calc later
}


int ImprovableProperty::getRent () const {

	for (auto it = set_ownership.begin(); it != set_ownership.end(); ++it){
		
		if (set_ownership.begin()->second == 'z'){
			return rent;
		}

		if (it->second != (set_ownership.begin()->second) ){
			return rent;
		}
	}

	return rent * 10; //temp, add calculations later
}

