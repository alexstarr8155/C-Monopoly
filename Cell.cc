#include "Cell.h"
using namespace std;

Cell::Cell (const string & name): name{name} {
	numImprovements = -1;
	on_cell = {
		{'G', false},
		{'B', false},
		{'D', false},
		{'P', false},
		{'S', false},
		{'$', false},
		{'L', false},
		{'T', false}
	};
}

string Cell::getName () const {
	return name;
}

map<char, bool> Cell::who_on_cell () {
	return on_cell;
}

int Cell::getNumImprov () const {
	return numImprovements;
}


/* delete this after */
void Cell::notify (Subject &whoNotified) {
	cout << "I am notifying" << endl;
}

shared_ptr<Player> Cell::getOwner() {
	cout << "I am getting Owner" << endl;
	return nullptr;
}




