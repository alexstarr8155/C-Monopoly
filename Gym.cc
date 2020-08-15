#include "Gym.h"
using namespace std;

Gym::Gym (const string &name, vector<string> set) : Property{name, 150, set} {
	numImprovements = -2;
}

// returns the cost of landing on the gym
int Gym::getRent() const {
	return -666; //temp, add calc
}
