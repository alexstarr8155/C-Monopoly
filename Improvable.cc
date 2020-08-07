#include "Improvable.h"
using namespace std;


ImprovableProperty::ImprovableProperty (string &name, int price, int base_rent) : Property{name, price, base_rent} {
	numImprovements = 0;
}

void ImprovableProperty::upgrade (int num){
	numImprovements += num;
}

void ImprovableProperty::downgrade (int num){
	numImprovements -= num;
}

int ImprovableProperty::getValue () const {
	return 199; //temp 
}

int ImprovableProperty::getRent () const {
	return rent; //temp, add calculations later
}


