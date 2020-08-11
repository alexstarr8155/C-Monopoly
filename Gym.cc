#include "Gym.h"
using namespace std;

Gym::Gym (const string &name, vector<string> set) : Property{name, 150, set} {
	numImprovements = 0;
}

int Gym::getRent () const {
	return -666; //temp, add calc
}
