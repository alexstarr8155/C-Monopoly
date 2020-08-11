#include "Residence.h"
#include "Player.h"

using namespace std;

Residences::Residences (const string &name, vector<string> set): 
	Property{name, 200, set} {
	
	numImprovements = -1;
}

int Residences::getRent () const {
	int numOwned = 0;
	
	if (!owner){
		return 0;
	}

	for (auto it = set_ownership.begin(); it != set_ownership.end(); ++it) {
		if (it->second == owner->getPlayerChar()){
			numOwned++;
		}
	}
	
	switch (numOwned){
		case 1:
			return 25;
		case 2:
			return 50;
		case 3:
			return 100;
		case 4:
			return 200;
	}
}

