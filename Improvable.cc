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
	return rent; //temp, add calculations later
}

void ImprovableProperty::notify (Subject &whoNotified) {
	cout << "I have been notified!" << endl; //temp
}	

