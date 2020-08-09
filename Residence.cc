#include "Residence.h"
using namespace std;

Residences::Residences (const string &name, int price, int base_rent) : Property{name, price, base_rent} {
	numImprovements = 0;
}

int Residences::getRent () const {
	return rent; //temp, add calc
}
