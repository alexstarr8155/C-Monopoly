#include "Gym.h"
using namespace std;

Gym::Gym (const string &name, int price, int base_rent) : Property{name, price, base_rent} {
	numImprovements = 0;
}

int Gym::getRent () const {
	return rent; //temp, add calc
}
