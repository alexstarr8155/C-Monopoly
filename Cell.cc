#include "Cell.h"
#include "Player.h"
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

void Cell::leave (shared_ptr<Player> p){ 
	on_cell.at(p->getPlayerChar ()) = false;
}

map<char, bool> Cell::who_on_cell () {
	return on_cell;
}

int Cell::getNumImprov () const {
	return numImprovements;
}


