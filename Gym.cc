#include "Gym.h"
using namespace std;

Gym::Gym (const string &name, int price, int base_rent, vector<string> set) : Property{name, price, set}, base_rent{base_rent} {
	numImprovements = 0;
}

int Gym::getRent () const {
	return base_rent; //temp, add calc
}
