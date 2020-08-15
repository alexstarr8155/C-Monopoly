#include "Gym.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Gym::Gym (const string &name, vector<string> set) : Property{name, 150, set} {
	numImprovements = -2;
}

// returns the cost of landing on the gym (dependent on dice roll and if set is complete)
int Gym::getRent() const {
	
	srand ((unsigned int)time(NULL));

	int dice1 = 1 + (rand() % 6);
	int dice2 = 1 + (rand() % 6);
	cout << dice1 << " " << dice2 << endl;

	int sum = dice1 + dice2;

	int numOwned = 0;
	for (auto it = set_ownership.begin(); it != set_ownership.end(); ++it) {
		if (it->second == owner->getPlayerChar()){
			numOwned++;
		}
	}

	switch (numOwned) {
		case 1:
			return sum * 4;
		case 2:
			return sum * 10;
	}
}
