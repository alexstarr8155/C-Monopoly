#include "Residence.h"
using namespace std;

Residences::Residences (const string &name, int price, int base_rent, vector<string> set): 
	Property{name, price, set}, base_rent{base_rent} {
	
	numImprovements = 0;
}

int Residences::getRent () const {
	return base_rent; //temp, add calc
}
